#include <iostream>

using namespace std;

int w(int a, int b, int c, int dp[21][21][21]);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int dp[21][21][21];

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				dp[i][j][k] = -10000000;
			}
		}
	}

	while (true) {
		int a, b, c;

		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c, dp) << '\n';
	}

	return 0;
}

int w(int a, int b, int c, int dp[21][21][21]) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20, dp);

	if (dp[a][b][c] != -10000000)
		return dp[a][b][c];

	if (a < b && b < c)
		dp[a][b][c] = w(a, b, c - 1, dp) + w(a, b - 1, c - 1, dp) - w(a, b - 1, c, dp);
	else
		dp[a][b][c] = w(a - 1, b, c, dp) + w(a - 1, b - 1, c, dp) + w(a - 1, b, c - 1, dp) - w(a - 1, b - 1, c - 1, dp);

	return dp[a][b][c];
}