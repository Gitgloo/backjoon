#include <iostream>
#include <queue>
#include <stack>

#define INF 100000001

using namespace std;

struct edge {
	int v, w;
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
		edgeArray[u].push_back({ v, w });
	}
	
	cin >> start >> end;
	dist[start] = 0;
	pq.push({ start, 0 });

	while (pq.size()) {
		edge nowEdge = pq.top();
		pq.pop();
			
		if (nowEdge.w < dist[end]) {
			vector<edge> edges = edgeArray[nowEdge.v];
			for (int i = 0; i < edges.size(); i++) {
				int nextDist = nowEdge.w + edges[i].w;
				if (nextDist < dist[edges[i].v]) {
					dist[edges[i].v] = nextDist;
					save[edges[i].v] = nowEdge.v;
					pq.push({ edges[i].v, nextDist });
				}
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