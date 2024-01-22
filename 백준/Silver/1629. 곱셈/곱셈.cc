#include <iostream>

using namespace std;

int recur(int a, int b, int c);

int main(void) {
	int a, b, c;

	cin >> a >> b >> c;

	cout << recur(a, b, c) << endl;

	return 0;
}

int recur(int a, int b, int c) {
	if (b == 1)
		return a % c;

	int half = recur(a, b / 2, c);
	long long int temp = 1LL * half * half % c;
	if (b % 2)
		temp = temp * a % c;
	return temp;
}