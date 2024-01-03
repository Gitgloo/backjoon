#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0)
			break;
		cout << a + b << '\n';
	}

	return 0;
}