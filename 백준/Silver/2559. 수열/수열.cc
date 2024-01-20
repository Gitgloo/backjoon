#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	int* arr = new int[n + 1]();
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int max = -10000000;
	for (int i = k; i <= n; i++) {
		max = MAX(max, arr[i] - arr[i - k]);
	}

	cout << max << '\n';

	return 0;
}