#include <iostream>

using namespace std;

int main(void) {
	int b, ans = 0;
	string n;

	cin >> n >> b;
	for (int i = 0; i < n.length(); i++) {
		char ch = n[i];
		if (ch >= '0' && ch <= '9') {
			ans = b * ans + ch - '0';
		} else {
			ans = b * ans + ch - 'A' + 10;
		}
	}

	cout << ans << endl;

	return 0;
}