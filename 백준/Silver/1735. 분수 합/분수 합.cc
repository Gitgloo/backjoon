#include <iostream>

using namespace std;

int gcd(int a, int b);

int main(void) {
	int c1, m1, c2, m2, c, m, r;

	cin >> c1 >> m1 >> c2 >> m2;

	c = c1 * m2 + c2 * m1;
	m = m1 * m2;
	r = gcd(m, c);

	cout << c / r << ' ' << m / r << endl;

	return 0;
}

int gcd(int a, int b) {
	if (b > a)
		return gcd(b, a);

	int r = a % b;

	if (r == 0)
		return b;

	return gcd(b, r);
}