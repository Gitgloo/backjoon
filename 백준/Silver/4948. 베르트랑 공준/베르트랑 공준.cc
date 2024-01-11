#include <iostream>

using namespace std;

int main(void) {
	bool arr[123456 * 2 + 1] = { false };
	arr[1] = true;
	for (int i = 2; i < 123456 * 2 + 1; i++) {
		for (int j = 2 * i; j < 123456 * 2 + 1; j += i) {
			arr[j] = true;
		}
	}

	while (true) {
		int n, count{ 0 };

		cin >> n;
		if (n == 0)
			break;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == false)
				count++;
		}

		cout << count << '\n';
	}

	return 0;
}