#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int start);

vector<int> edgeArray[20001];
bool visited[2][20001];

int main(void) {
	int k;

	cin >> k;
	while (k--) {
		int v, e;
		bool result = true;

		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			edgeArray[i].clear();
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= v; j++) {
				visited[i][j] = false;
			}
		}

		while (e--) {
			int a, b;

			cin >> a >> b;
			edgeArray[a].push_back(b);
			edgeArray[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (!visited[0][i] && !visited[1][i] && !bfs(i)) {
				result = false;
				break;
			}
		}

		cout << (result ? "YES\n" : "NO\n");
	}

	return 0;
}

bool bfs(int start) {
	int team = 0;
	queue<int> q;
	q.push(start);
	visited[0][start] = true;

	while (true) {
		int stepSize = q.size();
		if (stepSize == 0)
			break;
		team ^= 1;
		for (int i = 0; i < stepSize; i++) {
			int now = q.front();
			
			q.pop();
			vector<int> edges = edgeArray[now];
			for (int i = 0; i < edges.size(); i++) {
				int next = edges[i];
				if (visited[team ^ 1][next])
					return false;
				if (!visited[team][next]) {
					visited[team][next] = true;
					q.push(next);
				}
			}
		}
	}

	return true;
}