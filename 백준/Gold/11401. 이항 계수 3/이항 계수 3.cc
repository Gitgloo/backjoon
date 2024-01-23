#include <iostream>

using namespace std;

int recur(int n, int k);

int main(void) {
	int n, k;
	long long int ans{ 1 }, temp{ 1 };

	cin >> n >> k;

	for (int i = n - k + 1; i <= n; i++) {
		ans = ans * i % 1000000007;
	}

	for (int i = 1; i <= k; i++) {
		temp = temp * i % 1000000007;
	}

	ans = ans * recur(temp, 1000000007 - 2) % 1000000007;

	cout << ans << endl;

	return 0;
}

int recur(int n, int k) {
	if (k == 0)
		return 1;
	int temp = recur(n, k / 2);
	temp = (long long int)temp * temp % 1000000007;
	if (k % 2)
		temp = (long long int)temp * n % 1000000007;
	return temp;
}