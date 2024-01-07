#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;

	cin >> n >> m;

	vector<int> cards(n);

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	int answer = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = cards[i] + cards[j] + cards[k];
				if (temp > answer && temp <= m) {
					answer = temp;
				}
			}
		}
	}

	cout << answer << endl;

	return 0;
}