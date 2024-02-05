#include <iostream>
#include <queue>
#include <vector>

#define INF 3000001

using namespace std;

struct edge {
	int next, dist;
};

vector<edge> edgeArray[20001];
vector<int> distArray(20001, INF);

bool operator<(const edge& a, const edge& b) {
	return a.dist > b.dist;
}

void dijkstra(int start, int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int v, e, k;

	cin >> v >> e >> k;
	while (e--) {
		int u, v, w;

		cin >> u >> v >> w;
		edgeArray[u].push_back({ v, w });
	}

	dijkstra(k, v);

	for (int i = 1; i <= v; i++) {
		int dist = distArray[i];
		if (dist == INF)
			cout << "INF\n";
		else
			cout << dist << '\n';
	}

	return 0;
}

void dijkstra(int start, int n) {
	vector<bool> visited(n + 1, false);

	priority_queue<edge> pq;
	distArray[start] = 0;
	pq.push({ start, 0 });

	while (pq.size()) {
		edge nowNode = pq.top();
		pq.pop();
		int now = nowNode.next, nowDist = nowNode.dist;
		if (visited[now])
			continue;
		visited[now] = true;
		vector<edge> edges = edgeArray[now];
		for (auto edge : edges) {
			int next = edge.next, nextDist = nowDist + edge.dist;
			if (nextDist < distArray[next]) {
				distArray[next] = nextDist;
				pq.push({ next, nextDist });
			}
		}
	}
}