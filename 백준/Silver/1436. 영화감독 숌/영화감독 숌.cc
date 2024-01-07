#include <iostream>

using namespace std;

int main(void) {
	int n, count{ 0 }, i{ 665 };

	cin >> n;

	while (count < n) {
		int temp = ++i;
		while (temp > 665) {
			if (temp % 1000 == 666) {
				count++;
				break;
			}
			temp /= 10;
		}
	}

	cout << i << endl;

	return 0;
}