#include <iostream>
#include <queue>
#include <stack>

#define INF 100000001

using namespace std;

struct edge {
	int u, v, w;
};

bool operator<(edge a, edge b) {
	return a.w > b.w;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, start, end;
	vector<int> dist;
	vector<int> save;
	stack<int> sequence;
	priority_queue<edge> pq;
	vector<vector<edge>> edgeArray;
	
	cin >> n >> m;
	dist.resize(n + 1, INF);
	save.resize(n + 1);
	edgeArray.resize(n + 1);
	while (m--) {
		int u, v, w;

		cin >> u >> v >> w;
		edgeArray[u].push_back({ u, v, w });
	}
	
	cin >> start >> end;
	dist[start] = 0;
	for (int i = 0; i < edgeArray[start].size(); i++) {
		pq.push(edgeArray[start][i]);
	}

	while (pq.size()) {
		edge nowEdge = pq.top();
		pq.pop();

		int nextDist = dist[nowEdge.u] + nowEdge.w;
		if (nextDist < dist[nowEdge.v]) {
			dist[nowEdge.v] = nextDist;
			save[nowEdge.v] = nowEdge.u;
			vector<edge> edges = edgeArray[nowEdge.v];
			for (int i = 0; i < edges.size(); i++) {
				pq.push(edges[i]);
			}
		}
	}

	cout << dist[end] << '\n';

	sequence.push(end);
	while (end != start) {
		end = save[end];
		sequence.push(end);
	}

	cout << sequence.size() << '\n';
	while (sequence.size()) {
		cout << sequence.top() << ' ';
		sequence.pop();
	}
	cout << '\n';

	return 0;
}