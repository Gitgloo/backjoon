#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;

	getline(cin, str, '\n');

	int count = str[0] != ' ' ? 1 : 0;
	for (size_t i = 1; i < str.length(); i++) {
		if (str[i - 1] == ' ' && str[i] != ' ')
			count++;
	}

	cout << count << endl;

	return 0;
}