#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b);

int main(void) {
	long long int a, b;

	cin >> a >> b;
	cout << a * b / gcd(a, b) << endl;

	return 0;
}

long long int gcd(long long int a, long long int b) {
	if (b > a)
		return gcd(b, a);

	long long int r = a % b;

	if (r == 0)
		return b;

	return gcd(b, r);
}