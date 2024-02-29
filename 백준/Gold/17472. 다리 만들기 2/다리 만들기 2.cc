#include <iostream>
#include <queue>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int n, m, id = 2, map[10][10], edge[8][8];

void input();
void solve();

int main(void) {
	input();
	solve();
	
	return 0;
}

bool isRange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y) {
	static int dx[4] = { 1,0,-1,0 }, dy[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> q;

	map[x][y] = id;
	q.push({ x, y });
	while (q.size()) {
		pair<int, int> now = q.front();
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = now.first + dx[i], nextY = now.second + dy[i];

			if (isRange(nextX, nextY) && map[nextX][nextY] == 1) {
				map[nextX][nextY] = id;
				q.push({ nextX,nextY });
			}
		}
	}

	id++;
}

void findIslands() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
			}
		}
	}
}

void makeEdgeArray() {
	for (int i = 2; i < 8; i++) {
		for (int j = 2; j < 8; j++) {
			edge[i][j] = -10;
		}
	}

	for (int i = 0; i < n; i++) {
		int count = 0, start = map[i][0];
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				count++;
			} else {
				int end = map[i][j];

				if (count > 1 && start) {
					edge[start][end] = MAX(edge[start][end], -count);
					edge[end][start] = edge[start][end];
				}

				count = 0;
				start = end;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		int count = 0, start = map[0][j];
		for (int i = 0; i < n; i++) {
			if (map[i][j] == 0) {
				count++;
			} else {
				int end = map[i][j];

				if (count > 1 && start) {
					edge[start][end] = MAX(edge[start][end], -count);
					edge[end][start] = edge[start][end];
				}

				count = 0;
				start = end;
			}
		}
	}
}

void makeMST() {
	int sum = 0, start = 2, count = 3;
	bool visited[8] = { false };
	priority_queue<pair<int, int>> pq;

	visited[start] = true;
	for (int i = 2; i < 8; i++) {
		if (edge[start][i] == -10)
			continue;
		pq.push({ edge[start][i], i });
	}
	while (pq.size()) {
		pair<int, int> now = pq.top();
		pq.pop();

		if (visited[now.second])
			continue;
		visited[now.second] = true;
		sum -= now.first;
		for (int i = 2; i < 8; i++) {
			if (!visited[i] && edge[now.second][i] == -10)
				continue;
			pq.push({ edge[now.second][i], i });
		}
		count++;
	}

	cout << (count == id ? sum : -1) << '\n';
}

void solve() {
	// 섬 구분하기
	findIslands();

	// 섬 경로 구하기
	makeEdgeArray();

	// 최소 신장 트리 만들기
	makeMST();
}

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}