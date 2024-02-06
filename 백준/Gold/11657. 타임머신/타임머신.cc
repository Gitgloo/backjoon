#include <iostream>
#include <vector>

#define INF 10000000000000000

using namespace std;

struct edge {
	int u, v, w;
};

int main(void) {
	int n, m;

	cin >> n >> m;
	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		edges.push_back({ a, b, c });
	}
	vector<long> dist(n + 1, INF);
	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			edge now = edges[j];
			long nowDist = dist[now.u];
			if (nowDist == INF)
				continue;
			long nextDist = nowDist + now.w;
			if (nextDist < dist[now.v]) {
				dist[now.v] = nextDist;
				if (i == n) {
					cout << "-1\n";
					return 0;
				}
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
	}

	return 0;
}