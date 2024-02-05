#include <iostream>
#include <queue>
#include <vector>

#define INF 1600001
#define MIN(x, y) ((x) > (y) ? (y) : (x))

using namespace std;

struct edge {
	int next, dist;
};

vector<int> dijkstra(int start);

bool operator<(edge a, edge b) {
	return a.dist > b.dist;
}

int n;
vector<vector<edge>> edgeArray;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int e, v1, v2;

	cin >> n >> e;
	edgeArray = vector<vector<edge>>(n + 1);
	while (e--) {
		int a, b, c;

		cin >> a >> b >> c;
		edgeArray[a].push_back({ b, c });
		edgeArray[b].push_back({ a, c });
	}

	cin >> v1 >> v2;

	vector<int> distV1 = dijkstra(v1);
	vector<int> distV2 = dijkstra(v2);

	if (distV1[1] == INF || distV1[v2] == INF || distV1[n] == INF)
		cout << -1 << '\n';
	else
		cout << MIN((distV1[1] + distV1[v2] + distV2[n]), (distV2[1] + distV2[v1] + distV1[n])) << '\n';

	return 0;
}

vector<int> dijkstra(int start) {
	vector<int> dist(n + 1, INF);
	vector<bool> visited(n + 1, false);
	priority_queue<edge> pq;

	dist[start] = 0;
	pq.push({ start, 0 });
	while (pq.size()) {
		edge nowNode = pq.top();
		pq.pop();

		int now = nowNode.next, nowDist = nowNode.dist;
		if (visited[now])
			continue;

		visited[now] = true;
		
		for (auto nextNode : edgeArray[now]) {
			if (nowDist + nextNode.dist < dist[nextNode.next]) {
				dist[nextNode.next] = nowDist + nextNode.dist;
				pq.push({ nextNode.next, nowDist + nextNode.dist });
			}
		}
	}

	return dist;
}