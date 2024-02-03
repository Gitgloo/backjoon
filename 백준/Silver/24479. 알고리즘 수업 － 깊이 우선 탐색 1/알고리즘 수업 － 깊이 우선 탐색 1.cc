#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int now, vector<priority_queue<int, vector<int>, greater<int>>>& edgesArray, bool* visited);

int order = 0;
int* sequence;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;

	cin >> n >> m >> r;
	sequence = new int[n + 1]();
	bool* visited = new bool[n + 1]();
	vector<priority_queue<int, vector<int>, greater<int>>>	edgesArray(n + 1);
	
	while (m--) {
		int a, b;

		cin >> a >> b;
		edgesArray[a].push(b);
		edgesArray[b].push(a);
	}

	dfs(r, edgesArray, visited);

	for (int i = 1; i <= n; i++) {
		cout << *(sequence + i) << '\n';
	}

	delete[] sequence;
	delete[] visited;

	return 0;
}

void dfs(int now, vector<priority_queue<int, vector<int>, greater<int>>>& edgesArray, bool* visited) {
	*(visited + now) = true;
	*(sequence + now) = ++order;

	priority_queue<int, vector<int>, greater<int>> edges = edgesArray[now];
	while (edges.size()) {
		int next = edges.top();
		edges.pop();
		if (!*(visited + next)) {
			dfs(next, edgesArray, visited);
		}
	}
}