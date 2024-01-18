#include <iostream>

using namespace std;

int main(void) {
	int T;
	long long int dp[101];

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 5] + dp[i - 1];
	}

	cin >> T;
	while (T--) {
		int n;

		cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}