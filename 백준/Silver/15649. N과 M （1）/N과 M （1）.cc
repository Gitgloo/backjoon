#include <iostream>

using namespace std;

void recur(int n, int m, int check, int index, int* arr) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= n; i++) {
		if ((check & (1 << i)) > 0)
			continue;

		arr[index] = i;
		recur(n, m, check | (1 << i), index + 1, arr);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	int* arr = new int[n];

	recur(n, m, 0, 0, arr);

	delete[] arr;

	return 0;
}