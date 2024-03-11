#include <iostream>

#define MAX_N 15
#define MAX_K 100

using namespace std;

int n, k, modArr[MAX_N], lenArr[1 << MAX_N];
long long dp[1 << MAX_N][MAX_K];

void init();
void solve();

int main(void) {
	init();
	solve();

	return 0;
}

int getMod(int mod, int digit) {
	for (int i = 0; i < digit; i++) {
		mod = mod * 10;
		mod %= k;
	}

	return mod;
}

long long recur(int bits, int mod) {
	if (dp[bits][mod] == -1) {
		long long temp[MAX_K] = { 0 };

		for (int i = 0; i < n; i++) {
			if (bits & (1 << i)) {
				int tempBits = bits ^ (1 << i);
				int tempMod = getMod(modArr[i], lenArr[tempBits]);

				for (int j = 0; j < k; j++) {
					temp[j] += recur(tempBits, (k - tempMod + j) % k);
				}
			}
		}

		for (int i = 0; i < k; i++) {
			dp[bits][i] = temp[i];
		}
	}

	return dp[bits][mod];
}

long long fact(int n) {
	long long ret = 1;
	for (int i = 2; i <= n; i++) {
		ret *= i;
	}

	return ret;
}

long long gcd(long long a, long long b) {
	long long r = a % b;
	if (r == 0)
		return b;
	return gcd(b, r);
}

void solve() {
	long long possible = recur((1 << n) - 1, 0);

	if (possible) {
		long long total = fact(n);
		long long r = gcd(total, possible);
		cout << possible / r << '/' << total / r << '\n';
	} else {
		cout << "0/1\n";
	}
}

int getMod(string& num) {
	int temp = 0;

	for (int i = 0; i < num.size(); i++) {
		temp = temp * 10 + num[i] - '0';
		temp %= k;
	}

	return temp;
}

void init() {
	string arr[MAX_N];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> k;

	for (int i = 0; i < n; i++) {
		modArr[i] = getMod(arr[i]);
	}

	for (int i = 1; i < (1 << n); i++) {
		int j = 0;
		while ((i & (1 << j)) == 0) {
			j++;
		}

		lenArr[i] = lenArr[i ^ (1 << j)] + arr[j].size();
	}

	dp[0][0] = 1;

	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			dp[i][j] = -1;
		}
	}
}