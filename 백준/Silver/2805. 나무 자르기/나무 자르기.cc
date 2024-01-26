#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, left{ 0 }, right{ 2000000000 };

	cin >> n >> m;
	int* trees = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}

	while (left <= right) {
		int mid = (left + right) / 2;
		long long int sum = 0;

		for (int i = 0; i < n; i++) {
			int cut = trees[i] - mid;
			if (cut > 0)
				sum += cut;
		}

		if (sum > m) {
			left = mid + 1;
		} else if (sum < m) {
			right = mid - 1;
		} else {
			right = mid;
			break;
		}
	}

	cout << right << endl;

	return 0;
}