#include <iostream>
#include <queue>

#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

struct point {
	int r, c, wall;
};

bool isRange(int r, int c);

int n, m;

int main(void) {
	int ** visited[2], dr[4] = { -1,0,1,0 }, dc[4] = { 0,1,0,-1 };
	bool** map;
	queue<point> q;

	cin >> n >> m;

	map = new bool* [n];
	for (int i = 0; i < n; i++) {
		string line;

		cin >> line;
		*(map + i) = new bool[m];
		for (int j = 0; j < line.length(); j++) {
			*(*(map + i) + j) = line[j] == '1';
		}
	}
	for (int i = 0; i < 2; i++) {
		*(visited + i) = new int* [n];
		for (int j = 0; j < n; j++) {
			*(*(visited + i) + j) = new int[m]();
		}
	}

	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;

	while (q.size()) {
		point now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextR = now.r + dr[i], nextC = now.c + dc[i], nowCount = visited[now.wall][now.r][now.c];

			if (isRange(nextR, nextC)) {
				if (map[nextR][nextC]){
					if (!now.wall && !visited[1][nextR][nextC]) {
						visited[1][nextR][nextC] = nowCount + 1;
						q.push({ nextR, nextC, 1 });
					}
				} else {
					if (!visited[now.wall][nextR][nextC]) {
						visited[now.wall][nextR][nextC] = nowCount + 1;
						q.push({ nextR, nextC, now.wall });
					}
				}
			}
		}
	}

	int first = visited[0][n - 1][m - 1], second = visited[1][n - 1][m - 1];
	
	if (first + second) {
		if (first == 0)
			cout << second << '\n';
		else if (second == 0)
			cout << first << '\n';
		else
			cout << MIN(first, second) << '\n';
	}
	else {
		cout << "-1\n";
	}

	
	for (int i = 0; i < n; i++) {
		delete[] *(map + i);
	}
	delete[] map;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			delete[] *(*(visited + i) + j);
		}
		delete[] *(visited + i);
	}

	return 0;
}

bool isRange(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}