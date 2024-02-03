#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(int n, vector<int>* edgeArray, int r);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;

	cin >> n >> m >> r;
	vector<int>* edgeArray = new vector<int>[n + 1];

	while (m--) {
		int a, b;

		cin >> a >> b;
		edgeArray[a].push_back(b);
		edgeArray[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort((edgeArray + i)->begin(), (edgeArray + i)->end());
	}

	bfs(n, edgeArray, r);

	delete[] edgeArray;

	return 0;
}

void bfs(int n, vector<int>* edgeArray, int r) {
	int order = 1;
	int* visited = new int[n + 1]();
	queue<int> q;
	
	*(visited + r) = order++;
	q.push(r);
	while (q.size()) {
		int now = q.front();
		q.pop();
		vector<int> edges = *(edgeArray + now);
		for (int i = 0; i < edges.size(); i++) {
			int next = edges[i];
			if (!*(visited + next)) {
				*(visited + next) = order++;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << *(visited + i) << '\n';
	}

	delete[] visited;
}