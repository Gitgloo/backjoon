#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n, right{ 2147483647 };
	long long int left{ 1 };

	cin >> k >> n;

	int* arr = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> *(arr + i);
	}

	while (left <= right) {
		long long int count = 0;
		long long int mid = (left + right) / 2;

		for (int i = 0; i < k; i++) {
			count += *(arr + i) / mid;
		}

		if (count < n) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	cout << right << endl;

	delete[] arr;
	return 0;
}