#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	int n, k, max{ 0 };

	cin >> n >> k;

	int* dp = new int[k + 1]();

	while (n--) {
		int w, v;

		cin >> w >> v;
		if (w > k)
			continue;

		for (int i = k; i >= w; i--) {
			dp[i] = MAX(dp[i], dp[i - w] + v);
		}
	}

	for (int i = 1; i <= k; i++) {
		max = MAX(max, dp[i]);
	}

	cout << max << endl;

	return 0;
}