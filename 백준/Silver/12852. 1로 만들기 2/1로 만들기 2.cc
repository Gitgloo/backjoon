#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

int main(void) {
	int n;
	vector<int> arr, before;

	cin >> n;
	arr.resize(n + 1, INF);
	before.resize(n + 1);
	arr[1] = 0;
	for (int i = 1; i < n; i++) {
		int next = arr[i] + 1;
		if (3 * i <= n && next < arr[3 * i]) {
			arr[3 * i] = next;
			before[3 * i] = i;
		}
		if (2 * i <= n && next < arr[2 * i]) {
			arr[2 * i] = next;
			before[2 * i] = i;
		}
		if (i + 1 <= n && next < arr[i + 1]) {
			arr[i + 1] = next;
			before[i + 1] = i;
		}
	}

	cout << arr[n] << '\n';
	while (n >= 1) {
		cout << n << ' ';
		n = before[n];
	}
	cout << '\n';

	return 0;
}