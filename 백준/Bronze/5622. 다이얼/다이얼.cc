#include <iostream>

using namespace std;

int main(void) {
	int map[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9 ,9 ,9 };
	string str;

	cin >> str;

	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		count += map[str[i] - 'A'] + 1;
	}

	cout << count << endl;

	return 0;
}