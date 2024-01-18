#include <iostream>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int main(void) {
	int n;

	cin >> n;
	int* dp = new int[n + 1];
	dp[1] = 0;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if(i % 3 == 0)
			dp[i] = MIN(dp[i], dp[i / 3] + 1);

		if (i % 2 == 0)
			dp[i] = MIN(dp[i], dp[i / 2] + 1);
	}

	cout << dp[n] << endl;

	delete[] dp;
	dp = nullptr;

	return 0;
}