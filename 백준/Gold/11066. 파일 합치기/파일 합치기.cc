#include <iostream>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int k, arr[501];
int** dp;

int recur(int left, int right);

int main(void) {
	int t;

	cin >> t;
	*arr = 0;
	while (t--) {
		cin >> k;

		dp = new int* [k + 1];
		for (int i = 1; i <= k; i++) {
			cin >> *(arr + i);

			dp[i] = new int[k + 1]();
			for (int j = 1; j <= k; j++) {
				*(*(dp + i) + j) = -1;
			}
			*(*(dp + i) + i) = 0;
			*(arr + i) += *(arr + i - 1);
		}

		cout << recur(1, k) << '\n';


		for (int i = 1; i <= k; i++) {
			delete[] *(dp + i);
		}
		delete[] dp;
	}

	return 0;
}

int recur(int left, int right) {
	if (*(*(dp + left) + right) != -1)
		return *(*(dp + left) + right);

	int min = recur(left, right - 1);
	for (int i = left; i < right - 1; i++) {
		min = MIN(min, recur(left, i) + recur(i + 1, right));
	}

	*(*(dp + left) + right) = min + *(arr + right) - *(arr + left - 1);

	return *(*(dp + left) + right);
}