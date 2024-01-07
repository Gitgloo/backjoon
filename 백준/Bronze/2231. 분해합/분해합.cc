#include <iostream>

using namespace std;

int main(void) {
	int n, answer{0};

	cin >> n;
	
	for (int i = 1; i < n; i++) {
		int temp = i, num = i;

		while (num) {
			temp += num % 10;
			num /= 10;
		}

		if (temp == n) {
			answer = i;
			break;
		}
	}

	cout << answer << endl;

	return 0;
}