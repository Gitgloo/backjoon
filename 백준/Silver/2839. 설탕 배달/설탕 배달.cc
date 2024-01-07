#include <iostream>

using namespace std;

int main(void) {
	int n, answer{ -1 };

	cin >> n;
	for (int i = n / 5; i >= 0; i--) {
		if ((n - 5 * i) % 3 == 0) {
			answer = i + (n - 5 * i) / 3;
			break;
		}
	}

	cout << answer << endl;

	return 0;
}