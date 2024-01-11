#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;

	cin >> m >> n;

	bool* arr = new bool[n + 1] { false };

	arr[1] = true;
	for (int i = 2; i <= n; i++) {
		for (int j = 2 * i; j <= n; j += i) {
			arr[j] = true;
		}
	}

	for (int i = m; i <= n; i++) {
		if (arr[i] == false) {
			cout << i << '\n';
		}
	}
	return 0;
}