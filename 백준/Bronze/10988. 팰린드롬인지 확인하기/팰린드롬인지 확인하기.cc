#include <iostream>

using namespace std;

int main(void) {
	string str;

	cin >> str;

	int len = str.length();
	int ans = 1;
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - 1 - i]) {
			ans = 0;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}