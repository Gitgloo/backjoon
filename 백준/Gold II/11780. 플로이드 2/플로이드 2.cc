#include <iostream>
#include <queue>

#define INF 1000000000
#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	queue<int> path;

	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, INF));
	vector<vector<int>> save(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			save[i][j] = j;
		}
	}


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
					save[i][j] = save[i][k];
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
			if (arr[i][j] == INF) {
				cout << "0\n";
			} else {
				int now = i;
				path.push(now);
				while (now != j) {
					now = save[now][j];
					path.push(now);
				}
				cout << path.size();
				while (path.size()) {
					cout << ' ' << path.front();
					path.pop();
				}
				cout << '\n';
			}
		}
	}

	return 0;
}