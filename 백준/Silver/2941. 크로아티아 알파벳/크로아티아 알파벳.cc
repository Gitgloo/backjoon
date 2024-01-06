#include <iostream>

using namespace std;

int main(void) {
	int count = 0;
	string str;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		char now = str[i];

		if (i + 1 != str.length()) {
			char next = str[i + 1];
			if (now == 'c') {
				if (next == '=' || next == '-') {
					i++;
				}
			} else if (now == 'd') {
				if (next == 'z' && i + 2 != str.length() && str[i + 2] == '=') {
					i += 2;
				} else if (next == '-') {
					i++;
				}
			} else if (now == 'l' && next == 'j') {
				i++;
			} else if (now == 'n' && next == 'j') {
				i++;
			} else if (now == 's' && next == '=') {
				i++;
			} else if (now == 'z' && next == '=') {
				i++;
			}
		}
		count++;
	}
	cout << count << endl;

	return 0;
}