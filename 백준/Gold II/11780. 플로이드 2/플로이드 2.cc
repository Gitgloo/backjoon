#include <iostream>
#include <vector>

#define INF 1000000000
#define MIN(x, y) ((x) > (y) ? (y) : (x))
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, INF));
	vector<vector<vector<int>>> save(n + 1, vector<vector<int>>(n + 1));

	while (m--) {
		int a, b, c;

		cin >> a >> b >> c;
		arr[a][b] = MIN(arr[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)
					continue;
				int temp = arr[i][k] + arr[k][j];
				if (temp < arr[i][j]) {
					arr[i][j] = temp;
					vector<int>& nowSave = save[i][j];
					vector<int>& frontSave = save[i][k];
					vector<int>& backSave = save[k][j];
					nowSave.clear();
					for (int l = 0; l < frontSave.size(); l++) {
						nowSave.push_back(frontSave[l]);
					}
					nowSave.push_back(k);
					for (int l = 0; l < backSave.size(); l++) {
						nowSave.push_back(backSave[l]);
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (arr[i][j] == INF ? 0 : arr[i][j]) << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> temp = save[i][j];
			if (arr[i][j] == INF) {
				cout << "0\n";
			} else {
				cout << temp.size() + 2 << ' ' << i;
				for (int k = 0; k < temp.size(); k++) {
					cout << ' ' << temp[k];
				}
				cout << ' ' << j << '\n';
			}
		}
	}

	return 0;
}