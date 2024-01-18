#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	int n;

	cin >> n;

	int* step = new int[n];
	int* dp = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> step[i];
	}

	dp[0] = step[0];
	if (n > 1)
		dp[1] = dp[0] + step[1];
	if (n > 2)
		dp[2] = MAX(step[0], step[1]) + step[2];
	for (int i = 3; i < n; i++) {
		dp[i] = MAX(dp[i - 2], dp[i - 3] + step[i - 1]) + step[i];
	}

	cout << dp[n - 1] << endl;

	return 0;
}