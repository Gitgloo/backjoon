#include <iostream>
#include <math.h>

#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define MAX_N 1000
#define INF 100000000

using namespace std;

void input();
void init();
void solve();

int n, dp[MAX_N][9], cost[MAX_N][3];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	init();
	solve();

	return 0;
}

int recur(int index, int type) {
	if (dp[index][type] == 0) {
		int nextCost = INF;

		for (int i = 1; i <= 2; i++) {
			nextCost = min(nextCost, recur(index + 1, (type + 3 * i) % 9));
		}

		dp[index][type] = nextCost + cost[index][type / 3];
	}

	return dp[index][type];
}

void solve() {
	int minCost = INF;

	for (int i = 0; i < 9; i++) {
		if (i % 3 != i / 3)
			minCost = min(minCost, recur(0, i));
	}

	cout << minCost << '\n';
}

void init() {
	for (int i = 0; i < 9; i++) {
		if (i % 3 == i / 3) {
			dp[n - 1][i] = cost[n - 1][i % 3];
		} else {
			dp[n - 1][i] = INF;
		}
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
}