#include <iostream>

#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define MAX_N 16
#define INF 100000000

using namespace std;

int n, cost[MAX_N][MAX_N], dp[2 << MAX_N][MAX_N];

void input();
void solve();

int main(void) {
	input();
	solve();

	return 0;
}

int recur(int bits, int end) {
	if (dp[bits][end])
		return dp[bits][end];

	int tempBits = bits - (bits & (1 << end)), min = INF;

	if (tempBits == 1)
		return dp[bits][end] = (cost[0][end] ? cost[0][end] : INF);

	for (int i = 1; i < n; i++) {
		if ((tempBits & (1 << i)) == 0 || cost[i][end] == 0)
			continue;

		min = MIN(min, recur(tempBits, i) + cost[i][end]);
	}

	return dp[bits][end] = min;
}

void solve() {
	int ans = INF;

	int bits = (1 << n) - 1;
	for (int i = 1; i < n; i++) {
		if(cost[i][0])
			ans = MIN(ans, recur(bits, i) + cost[i][0]);
	}

	cout << ans << '\n';
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
}