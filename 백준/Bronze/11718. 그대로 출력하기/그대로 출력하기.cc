#include <iostream>
#include <string>

using namespace std;

int main(void) {
	while (true) {
		string str;
		getline(cin, str, '\n');

		if (cin.eof())
			break;

		cout << str << endl;
	}
	return 0;
}