#include <iostream>

using namespace std;

int main(void) {
	int n, sum = 0;
	string str;
	
	cin >> n >> str;

	for (int i = 0; i < n; i++) {
		sum += str[i] - '0';
	}

	cout << sum << endl;

	return 0;
}