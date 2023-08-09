#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <chrono>
#include <algorithm>

using namespace std;

int main()
{
	cout << "make already start..." << endl;
	auto t_start = std::chrono::steady_clock::now();
	unsigned count = 0;

	string start("#include <iostream>\n\
using namespace std;\n\
int main(){\n\
\tcout << \"Please give a positive integer with no more than 5 digits\" << endl;\n\
\tint x;\n\
\tcin >> x;\n\
\t\n\
\tswitch(x){\n");

	ofstream ofs("print_1_To_10o5.cpp", ios::trunc);

	ofs << start;

	while (++count < 100000)
	{
		string tmp("\tcase "), str = to_string(count);
		unsigned mode = log10(count) + 1;
		tmp += to_string(count) + ":\n";

		tmp += "\t\tcout << \"digits' counts:" + to_string(mode) + "\" << endl;\n";

		tmp += "\t\tcout << \"single digit is: " + to_string(count % 10) + "\" << endl;\n";
		if (mode > 1)
		{
			tmp += "\t\tcout << \"tens digit is: " + to_string((count / 10) % 10) + "\" << endl;\n";
		}
		if (mode > 2)
		{
			tmp += "\t\tcout << \"The hundreds digit is: " + to_string((count / 100) % 10) + "\" << endl;\n";
		}
		if (mode > 3)
		{
			tmp += "\t\tcout << \"The thousands digit is: " + to_string((count / 1000) % 10) + "\" << endl;\n";
		}
		if (mode > 4)
		{
			tmp += "\t\tcout << \"The tens of thousands digit is: " + to_string((count / 10000) % 10) + "\" << endl;\n";
		}
		reverse(str.begin(), str.end());
		tmp += "\t\tcout << \"reverse: " + str + "\" << endl;\n";

		tmp += "\tbreak;\n";

		ofs << tmp;
	}

	ofs << "\n\t}\n}" << endl;

	ofs.close();
	cout << "make done." << endl;

	auto t_now = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = t_now - t_start;
	cerr << diff.count() << " seconds.\n";

	return 0;
}