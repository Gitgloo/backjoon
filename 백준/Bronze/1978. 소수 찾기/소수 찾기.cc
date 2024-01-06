#include <iostream>

using namespace std;

int main(void) {
	int n, count{0};

	cin >> n;
	while (n--) {
		int num;
		bool flag = true;

		cin >> num;
		if (num == 1) {
			flag = false;
		} else {
			for (int i = 2; i < num; i++) {
				if (num % i == 0) {
					flag = false;
					break;
				}
			}
		}

		if (flag)
			count++;
	}

	cout << count << endl;

	return 0;
}