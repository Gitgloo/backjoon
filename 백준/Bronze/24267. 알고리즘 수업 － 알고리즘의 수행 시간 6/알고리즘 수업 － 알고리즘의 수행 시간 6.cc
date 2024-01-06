#include <iostream>

using namespace std;

int main(void) {
	int n;
	long long repeat = 0;

	cin >> n;

	for (int i = n - 2; i >= 1; i--) {
		repeat += (long long)i * (n - 2 - i + 1);
	}
	cout << repeat << endl << 3 << endl;

	return 0;
}