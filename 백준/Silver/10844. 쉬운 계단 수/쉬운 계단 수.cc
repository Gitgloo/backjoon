#include <iostream>

using namespace std;

int main(void) {
	int n;

	cin >> n;

	if (n == 1) {
		cout << 9 << endl;
		return 0;
	}

	if (n == 2) {
		cout << 17 << endl;
		return 0;
	}

	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[10];
	}

	for (int i = 0; i <= 9; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8];
	}

	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans = (ans + dp[n - 1][i]) % 1000000000;
	}

	cout << ans << endl;

	for (int i = 0; i < n; i++) {
		delete[] dp[i];
	}

	delete[] dp;
	dp = nullptr;

	return 0;
}