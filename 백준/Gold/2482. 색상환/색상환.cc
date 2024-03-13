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

//int recur(int range, int count) {
//	if (dp[range][count] == 0) {
//		int nextCount = count - 1;
//		int possible = 2 * nextCount - 1;
//		long long sum = 0;
//
//		for (int i = range - 2; i >= possible; i--) {
//			sum += recur(i, nextCount);
//		}
//		
//		dp[range][count] = sum % MOD;
//	}
//
//	return dp[range][count];
//}

void solve() {
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	/*if (n / 2 < k) {
		cout << "0\n";
		return;
	}

	if (k == 1) {
		cout << n << '\n';
		return;
	}

	int nextK = k - 1;
	int possible = nextK * 2 - 1;
	long long ans = recur(n - 3, nextK);

	for (int i = n - 3; i >= possible; i--) {
		ans += recur(i, nextK);
	}
	
	cout << ans % MOD << '\n';*/

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