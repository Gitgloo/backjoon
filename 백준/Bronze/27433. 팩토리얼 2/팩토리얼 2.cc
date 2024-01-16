#include <iostream>

using namespace std;

long long int facto(int n) {
	if (n == 0)
		return 1;
	return facto(n - 1) * n;
}

int main(void) {
	int n;

	cin >> n;
	cout << facto(n) << endl;

	return 0;
}