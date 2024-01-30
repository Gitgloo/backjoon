#include <iostream>

using namespace std;

int main(void) {
	int n, k, dp[2][10001] = { {1} };

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int coin;

		cin >> coin;
		for (int j = 0; j < k; j++) {
			for (int l = j + coin; l <= k; l += coin) {
				dp[(i + 1) % 2][l] += dp[i % 2][j];
			}
		}

		for (int j = 0; j <= k; j++) {
			dp[(i + 1) % 2][j] += dp[i % 2][j];
			dp[i % 2][j] = 0;
		}
	}

	cout << dp[n % 2][k] << endl;

	return 0;
}