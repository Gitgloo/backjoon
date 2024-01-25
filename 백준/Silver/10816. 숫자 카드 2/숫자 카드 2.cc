#include <iostream>
#include <algorithm>

using namespace std;

int under(int find, int* arr, int n);
int upper(int find, int* arr, int n);

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

		int leftIndex = under(find, arr, n);
		if (*(arr + leftIndex) != find) {
			cout << 0 << ' ';
			continue;
		}
		int rightIndex = upper(find, arr, n);
		cout << rightIndex - leftIndex + 1 << ' ';
	}
	cout << '\n';

	delete[] arr;
	return 0;
}

int under(int find, int* arr, int n) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (*(arr +mid) < find) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return ++right;
}

int upper(int find, int* arr, int n) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] > find) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return --left;
}