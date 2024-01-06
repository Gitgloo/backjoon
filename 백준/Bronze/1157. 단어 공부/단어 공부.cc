#include <iostream>

using namespace std;

int main(void) {
	int count[26] = { 0 };
	string str;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (ch >= 'a' && ch <= 'z') {
			count[ch - 'a']++;
		}
		else {
			count[ch - 'A']++;
		}
	}

	int max = 0;
	char ans = '?';
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			ans = i + 'A';
		}
		else if (count[i] == max) {
			ans = '?';
		}
	}

	cout << ans << endl;

	return 0;
}