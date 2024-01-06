#include <iostream>

using namespace std;

int main(void) {
	int a, b, c, max{ 0 }, minSum;

	cin >> a >> b >> c;

	if (max < a) {
		max = a;
	}
	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}

	minSum = a + b + c - max;

	if (max < minSum) {
		cout << max + minSum << endl;
	} else {
		cout << 2 * minSum - 1 << endl;
	}
	return 0;
}