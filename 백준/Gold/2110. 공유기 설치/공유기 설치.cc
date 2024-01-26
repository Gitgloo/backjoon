#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c, left{ 0 }, right{ 1000000000 };

	cin >> n >> c;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	while (left <= right) {
		int before = arr[0], count = 1;
		int mid = (left + right) / 2;
		
		for (int i = 0; i < n; i++) {
			if (arr[i] - before >= mid) {
				before = arr[i];
				count++;
			}
		}

		if (count < c) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	cout << right << endl;

	delete[] arr;

	return 0;
}