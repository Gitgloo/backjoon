#include <iostream>
#include <queue>
#include <algorithm>

#define INF 50000001

using namespace std;

struct edge {
	int v, w;
};

int T, n, m, t, s, g, h, a, b, d, x;
vector<vector<edge>> edgeArray;
vector<int> dest;

vector<int> dijkstra();

bool operator<(edge a, edge b) {
	return a.w > b.w;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;
	while (T--) {

		cin >> n >> m >> t >> s >> g >> h;
		edgeArray = vector<vector<edge>>(n + 1);
		while (m--) {
			cin >> a >> b >> d;
			edgeArray[a].push_back({ b, d });
			edgeArray[b].push_back({ a, d });
		}
		dest.clear();
		while (t--) {
			cin >> x;
			dest.push_back(x);
		}

		vector<int> distOrigin = dijkstra();

		int diff = 0;
		for (int i = 0; i < edgeArray[g].size(); i++) {
			if (edgeArray[g][i].v == h) {
				diff = edgeArray[g][i].w;
				edgeArray[g][i].w = 0;
				break;
			}
		}
		for (int i = 0; i < edgeArray[h].size(); i++) {
			if (edgeArray[h][i].v == g) {
				edgeArray[h][i].w = 0;
				break;
			}
		}

		sort(dest.begin(), dest.end());
		vector<int> distChange = dijkstra();
		for (auto maybe : dest) {
			if (distOrigin[maybe] - distChange[maybe] == diff) {
				cout << maybe << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}

vector<int> dijkstra() {
	vector<int> dist = vector<int>(n + 1, INF);
	dist[s] = 0;

	priority_queue<edge> pq;
	pq.push({ s, 0 });
	while (pq.size()) {
		edge nowEdge = pq.top();
		pq.pop();
		for (auto nextEdge : edgeArray[nowEdge.v]) {
			int next = nextEdge.v;
			int nextDist = nowEdge.w + nextEdge.w;
			if (nextDist < dist[next]) {
				dist[next] = nextDist;
				pq.push({ next, nextDist });
			}
		}
	}

	return dist;
}