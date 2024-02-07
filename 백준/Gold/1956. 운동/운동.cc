#include <iostream>
#include <vector>

#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define INF 1000000000

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e;

	cin >> v >> e;
	vector<vector<int>> arr(v + 1, vector<int>(v + 1, INF));
	while (e--) {
		int a, b;

		cin >> a >> b;
		cin >> arr[a][b];
	}

	for (int i = 1; i <= v; i++) {
		arr[i][i] = 0;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				int temp = arr[i][k] + arr[k][j];
				if (temp < arr[i][j]) {
					arr[i][j] = temp;
				}
			}
		}
	}

	int min = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)
				continue;

			min = MIN(min, arr[i][j] + arr[j][i]);
		}
	}

	cout << (min == INF ? -1 : min) << '\n';

	return 0;
}