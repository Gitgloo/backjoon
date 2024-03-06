#include <iostream>

#define INF 200001
#define MAX_N 20
#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int recur(int bits, int now);

int n, cost[MAX_N][MAX_N], dp[1 << MAX_N];

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}

	for (int i = 1; i <= (1 << n) - 1; i++) {
		dp[i] = INF;
	}

	recur((1 << n) - 1, n - 1);

	cout << dp[(1 << n) - 1] << endl;

	return 0;
}

int recur(int bits, int now) {
	if (dp[bits] != INF)
		return dp[bits];

	int min = INF;

	for (int i = 0; i < n; i++) {
		if (bits & (1 << i)) {
			min = MIN(min, recur(bits & ~(1 << i), now - 1) + cost[now][i]);
		}
	}

	return dp[bits] = min;
}