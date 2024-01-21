#include <iostream>

using namespace std;

int main(void) {
	int num{ 0 }, sum{ 0 }, temp{ 0 };
	string str;

	cin >> str;
	int i = 0;
	for (; ; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = 10 * num + str[i] - '0';
		} else {
			sum += num;
			num = 0;

			if (str[i] == '-' || !str[i]) {
				break;
			}
		}
	}

	for (; ; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = 10 * num + str[i] - '0';
		}
		else if(str[i] == '+') {
			temp += num;
			num = 0;
		} else {
			sum -= temp + num;
			num = 0;
			temp = 0;
			if (!str[i])
				break;
		}
	}

	cout << sum << endl;

	return 0;
}