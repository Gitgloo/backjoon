#include <iostream>

#define MAX_N 1000
#define MOD 1000000003

using namespace std;

int n, k, dp[MAX_N][MAX_N + 1];

void init();
void solve();

int main(void) {
	init();
	solve();

	return 0;
}

void solve() {
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i < n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = ((long long)dp[i - 1][j] + dp[i - 2][j - 1]) % MOD;
		}
	}

	cout << ((long long)dp[n - 1][k] + dp[n - 3][k - 1]) % MOD << '\n';
}

void init() {
	cin >> n >> k;
}