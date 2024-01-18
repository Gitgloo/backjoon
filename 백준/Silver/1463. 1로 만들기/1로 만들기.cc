#include <iostream>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int cal(int* dp, int n);

int main(void) {
	int n;

	cin >> n;
	int* dp = new int[n + 1];
	dp[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = -1;
	}

	cout << cal(dp, n) << endl;

	delete[] dp;
	dp = nullptr;

	return 0;
}

int cal(int* dp, int n) {
	if (dp[n] >= 0)
		return dp[n];

	dp[n] = cal(dp, n - 1) + 1;

	if (n % 3 == 0)
		dp[n] = MIN(dp[n], cal(dp, n / 3) + 1);

	if (n % 2 == 0)
		dp[n] = MIN(dp[n], cal(dp, n / 2) + 1);

	return dp[n];
}