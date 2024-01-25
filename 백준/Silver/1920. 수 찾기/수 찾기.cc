#include <iostream>
#include <algorithm>

using namespace std;

bool isExist(int find, int* arr, int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> m;
	while (m--) {
		int find;

		cin >> find;
		cout << isExist(find, arr, n) << '\n';
	}

	return 0;
}

bool isExist(int find, int* arr, int n) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] > find) {
			right = mid - 1;
		} else if (arr[mid] < find) {
			left = mid + 1;
		} else {
			return true;
		}
	}

	return false;
}