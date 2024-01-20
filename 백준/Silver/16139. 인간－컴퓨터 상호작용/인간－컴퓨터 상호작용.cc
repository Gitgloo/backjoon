#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int q;
	string str;

	cin >> str >> q;
	int** arr = new int* ['z' - 'a' + 1];
	for (int i = 0; i <= 'z' - 'a'; i++) {
		arr[i] = new int[str.length() + 1]();
	}

	for (int i = 0; i <= 'z' - 'a'; i++) {
		for (int j = 1; j <= str.length(); j++) {
			arr[i][j] = (str[j - 1] == i + 'a') + arr[i][j - 1];
		}
	}

	while (q--) {
		char alpha;
		int l, r;

		cin >> alpha >> l >> r;
		cout << arr[alpha - 'a'][r + 1] - arr[alpha - 'a'][l] << '\n';
	}

	for (int i = 0; i <= 'z' - 'a'; i++) {
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}