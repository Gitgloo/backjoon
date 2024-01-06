#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;

	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m, 0));

	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int temp;

				cin >> temp;
				v[i][j] += temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}