#include <iostream>

using namespace std;

int gcd(int a, int b);

int main(void) {
	int T;

	cin >> T;
	while (T--) {
		int a, b;

		cin >> a >> b;

		int r = gcd(a, b);

		cout << a * b / r << endl;
	}

	return 0;
}

int gcd(int a, int b) {
	if (a < b)
		return gcd(b, a);

	int r = a % b;
	if (r == 0)
		return b;
	return gcd(b, r);
}