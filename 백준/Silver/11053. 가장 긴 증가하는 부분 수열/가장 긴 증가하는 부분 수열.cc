#include <iostream>
#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
	int n, ans{ 0 };

	cin >> n;
	int* arr = new int[n + 1]();
	int* dp = new int[n + 1]();

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
		ans = MAX(ans, dp[i]);
	}

	cout << ans << endl;

	return 0;
}