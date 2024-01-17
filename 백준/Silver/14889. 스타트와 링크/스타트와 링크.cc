#include <iostream>
#include <vector>

#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

void recur(int n, vector<vector<int>>& v, int check, int count, int index, int* min);
int getDiff(int n, vector<vector<int>>& v, int check);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, min{ 40000 };

	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	recur(n, v, 1, 1, 1, &min);

	cout << min << endl;

	return 0;
}

void recur(int n, vector<vector<int>>& v, int check, int count, int index, int* min) {
	if (count == n / 2) {
		int diff = getDiff(n, v, check);
		*min = MIN(*min, diff);
		return;
	}

	for (int i = index; i < n; i++) {
		recur(n, v, check | (1 << i), count + 1, i + 1, min);
	}
}

int getDiff(int n, vector<vector<int>>& v, int check) {
	int teamA = 0, teamB = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((check & (1 << i)) && (check & (1 << j)))
				teamA += v[i][j] + v[j][i];
			else if (!((check & (1 << i)) || (check & (1 << j))))
				teamB += v[i][j] + v[j][i];
		}
	}

	return ABS(teamA - teamB);
}