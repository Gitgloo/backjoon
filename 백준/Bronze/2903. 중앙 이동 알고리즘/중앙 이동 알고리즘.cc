#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int n, line = 1;

	cin >> n;

	line += pow(2, n);

	cout << (long)line * line << endl;

	return 0;
}