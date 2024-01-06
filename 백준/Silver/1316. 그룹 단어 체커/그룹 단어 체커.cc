#include <iostream>

using namespace std;

bool checkStr(string str);

int main(void) {
	int n, count = 0;

	cin >> n;
	while (n--) {
		string str;

		cin >> str;
		
		if (checkStr(str))
			count++;
	}

	cout << count << endl;

	return 0;
}

bool checkStr(string str) {
	bool check[26] = { false };

	for (int i = 0; i < str.length();) {
		char ch = str[i++];
		if (check[ch - 'a'])
			return false;
		check[ch - 'a'] = true;
		for (; i < str.length() && str[i] == ch; i++);
	}

	return true;
}