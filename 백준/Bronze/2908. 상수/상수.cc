#include <iostream>

using namespace std;

int changeToNum(string str);

int main(void) {
	string str1, str2;

	cin >> str1 >> str2;

	int num1 = changeToNum(str1), num2 = changeToNum(str2);

	int ans = num1 > num2 ? num1 : num2;
	cout << ans << endl;

	return 0;
}

int changeToNum(string str) {
	int num = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		num = 10 * num + str[i] - '0';
	}

	return num;
}