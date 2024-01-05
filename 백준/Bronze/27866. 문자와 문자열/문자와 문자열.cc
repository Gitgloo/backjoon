#include <iostream>

using namespace std;

int main(void) {
	int i;
	string str;

	cin >> str >> i;

	cout << str.at(i - 1) << endl;

	return 0;
}