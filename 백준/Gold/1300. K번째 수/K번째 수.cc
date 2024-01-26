#include <iostream>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int main(void) {
	int n, k, left{ 1 }, right;

	cin >> n >> k;

	right = k;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long int count = 0;
		
		for (int i = 1; i <= MIN(n, mid); i++) {
			count += MIN(n, mid / i);
		}

		if (count < k) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << left << endl;

	return 0;
}