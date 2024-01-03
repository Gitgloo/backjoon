#include <iostream>

using namespace std;

int main(void) {
	int n, sum;
	sum = 0;

	cin >> n;
	while (n) {
		sum += n--;
	}
	cout << sum << endl;

	return 0;
}