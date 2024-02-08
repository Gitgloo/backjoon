#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(void) {
	int n, left = 0, right = 0, sum = 0, count = 0;
	vector<int> primes;

	cin >> n;

	vector<bool> check(n + 1, false);
	for (int i = 2; i <= n; i++) {
		if (check[i])
			continue;
		primes.push_back(i);
		for (int j = i; j <= n; j += i) {
			check[j] = true;
		}
	}

	int primesSize = primes.size();
	while (true) {
		if (sum <= n) {
			if (sum == n) {
				count++;
			}
			if (right == primesSize) {
				break;
			}
			sum += primes[right++];
		}
		else {
			sum -= primes[left++];
		}
	}
	
	cout << count << '\n';

	return 0;
}