#include <iostream>

using namespace std;

int main(void) {
	int n;

	cin >> n;
	int* dp = new int[n > 2 ? n + 1 : 3];

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n] << endl;

	delete[] dp;

	return 0;
}