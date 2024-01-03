#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch = ' ';
			if (n - i <= j + 1)
				ch = '*';
			cout << ch;
		}
		cout << '\n';
	}
	return 0;
}