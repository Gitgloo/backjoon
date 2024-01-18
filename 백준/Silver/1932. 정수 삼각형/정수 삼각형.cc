#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	int n, max{ 0 };

	cin >> n;
	
	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[i + 1];
	}

	cin >> dp[0][0];
	for (int i = 1; i < n; i++) {
		cin >> dp[i][0];
		dp[i][0] += dp[i - 1][0];
		for (int j = 1; j < i; j++) {
			cin >> dp[i][j];
			dp[i][j] += MAX(dp[i - 1][j - 1], dp[i - 1][j]);
		}
		cin >> dp[i][i];
		dp[i][i] += dp[i - 1][i - 1];
	}

	for (int i = 0; i < n; i++) {
		max = MAX(max, dp[n - 1][i]);
	}

	cout << max << endl;

	for (int i = 0; i < n; i++) {
		delete[] dp[i];
	}
	delete dp;

	return 0;
}