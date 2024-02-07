#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, INF));
	while (m--) {
		int a, b, c;

		cin >> a >> b >> c;
		if(c < arr[a][b])
			arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		arr[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int temp = arr[i][k] + arr[k][j];
				
				if(temp < arr[i][j])
					arr[i][j] = temp;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (arr[i][j] == INF ? 0 : arr[i][j]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}