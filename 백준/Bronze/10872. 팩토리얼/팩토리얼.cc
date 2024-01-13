#include <iostream>

using namespace std;

int main(void) {
	int n, ans{ 1 };

	cin >> n;

	while (n) {
		ans *= n--;
	}

	cout << ans << endl;

	return 0;
}