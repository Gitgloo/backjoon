#include <iostream>

using namespace std;

int main(void) {
	int T;
	bool arr[1000000] = { false };

	arr[1] = true;
	for (int i = 2; i < 1000000; i++) {
		for (int j = 2 * i; j < 1000000; j += i) {
			arr[j] = true;
		}
	}

	cin >> T;
	while (T--) {
		int n, count{ 0 };
		
		cin >> n;
		for (int i = 2; i <= n / 2; i++) {
			if (arr[i] || arr[n - i])
				continue;
			count++;
		}

		cout << count << endl;
	}

	return 0;
}