#include <iostream>

using namespace std;

int main(void) {
	int n;

	cin >> n;
	for (int i = 2; n > 1; i++) {
		while (true) {
			if (n % i == 0) {
				cout << i << endl;
				n /= i;
			} else {
				break;
			}
		}
	}

	return 0;
}