#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	int* arr = new int[n + 1]();
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	while (m--) {
		int i, j;

		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << '\n';
	}

	delete[] arr;

	return 0;
}