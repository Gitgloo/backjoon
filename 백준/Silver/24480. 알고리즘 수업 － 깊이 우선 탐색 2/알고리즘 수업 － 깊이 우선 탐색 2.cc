#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int now, vector<priority_queue<int>>& edgesArray, int* visited);

int order = 0;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;

	cin >> n >> m >> r;
	int* visited = new int[n + 1]();
	vector<priority_queue<int>>	edgesArray(n + 1);
	
	while (m--) {
		int a, b;

		cin >> a >> b;
		edgesArray[a].push(b);
		edgesArray[b].push(a);
	}

	dfs(r, edgesArray, visited);

	for (int i = 1; i <= n; i++) {
		cout << *(visited + i) << '\n';
	}

	delete[] visited;

	return 0;
}

void dfs(int now, vector<priority_queue<int>>& edgesArray, int* visited) {
	*(visited + now) = ++order;

	priority_queue<int> edges = edgesArray[now];
	while (edges.size()) {
		int next = edges.top();
		edges.pop();
		if (!*(visited + next)) {
			dfs(next, edgesArray, visited);
		}
	}
}