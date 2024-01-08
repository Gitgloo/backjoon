#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, count[10001]{ 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		count[temp]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}