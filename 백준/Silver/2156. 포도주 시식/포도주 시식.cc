#include <iostream>

#define MAX2(x, y) ((x) > (y) ? (x) : (y))
#define MAX3(x, y, z) ((x) > (y) ? (x) > (z) ? (x) : (z) : (y) > (z) ? (y) : (z))

using namespace std;

int main(void) {
	int n;

	cin >> n;
	int* wine = new int[n + 1]();
	int* dp = new int[n + 1]();

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	dp[1] = wine[1];
	if (n > 1)
		dp[2] = wine[1] + wine[2];
	if(n > 2)
		dp[3] = MAX2(dp[1], wine[2]) + wine[3];
	for (int i = 4; i <= n; i++) {
		dp[i] = MAX3(dp[i - 2], dp[i - 3] + wine[i - 1], dp[i - 4] + wine[i - 1]) + wine[i];
	}

	cout << MAX2(dp[n - 1], dp[n]) << endl;

	delete[] wine;
	delete[] dp;
	wine = nullptr;
	dp = nullptr;

	return 0;
}