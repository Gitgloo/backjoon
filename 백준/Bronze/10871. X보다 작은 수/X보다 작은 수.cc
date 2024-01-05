#include <iostream>

using namespace std;

int main(void) {
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;

	cin >> n >> x;
	while (n--) {
		int input;
		cin >> input;
		if (input < x) {
			cout << input << ' ';
		}
	}
	cout << endl;

	return 0;
}