#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		long long int n;

		cin >> n;
		if (n <= 2) {
			cout << 2 << '\n';
		}
		else {
			for (long long int i = n; ; i++) {
				long long int j = 2;

				for (; j <= sqrt(i); j++) {
					if (i % j == 0)
						break;
				}

				if (i % j != 0) {
					cout << i << '\n';
					break;
				}
			}
		}
	}

	return 0;
}