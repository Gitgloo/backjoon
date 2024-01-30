#include <iostream>

using namespace std;

int main(void) {
	int n, k, dp[10001] = {1};

	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int coin;

		cin >> coin;
		for (int j = k; j >= coin; j--) {
			for (int l = coin; l <= j; l += coin) {
				dp[j] += dp[j - l];
			}
		}
	}

	cout << dp[k] << endl;

	return 0;
}