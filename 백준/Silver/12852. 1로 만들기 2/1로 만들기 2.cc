#include <iostream>
#include <vector>

#define INF 2147483647

using namespace std;

int main(void) {
	int n;
	vector<int> arr;

	cin >> n;
	arr.resize(n + 1, INF);
	arr[1] = 0;
	for (int i = 1; i < n; i++) {
		int next = arr[i] + 1;
		if (3 * i <= n && next < arr[3 * i]) {
			arr[3 * i] = next;
		}
		if (2 * i <= n && next < arr[2 * i]) {
			arr[2 * i] = next;
		}
		if (i + 1 <= n && next < arr[i + 1]) {
			arr[i + 1] = next;
		}
	}

	cout << arr[n] << '\n';
	while (n >= 1) {
		cout << n << ' ';
		int before = arr[n] - 1;
		if (n % 3 == 0 && before == arr[n / 3]) {
			n /= 3;
		} else if (n % 2 == 0 && before == arr[n / 2]) {
			n /= 2;
		} else {
			n--;
		}
	}
	cout << '\n';

	return 0;
}