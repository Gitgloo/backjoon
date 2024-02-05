#include <iostream>
#include <queue>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define INF 100001

using namespace std;

struct edge {
	int next, dist;
};

bool operator<(const edge a, edge b) {
	return a.dist > b.dist;
}

int main(void) {
	int n, k;
	
	cin >> n >> k;

	if (n >= k) {
		cout << n - k;

		return 0;
	}

	vector<int> dist = vector<int>(k + 2, INF);
	priority_queue<edge> pq;
	
	pq.push({ n, 0 });
	dist[n] = 0;
	while (pq.size()) {
		edge nowNode = pq.top();
		int now = nowNode.next, nowSeconds = nowNode.dist;
		pq.pop();

		if (now + 1 <= k && nowSeconds + 1 < dist[now + 1]) {
			dist[now + 1] = nowSeconds + 1;
			pq.push({ now + 1, nowSeconds + 1 });
		}

		if (now - 1 >= 0 && nowSeconds + 1 < dist[now - 1]) {
			dist[now - 1] = nowSeconds + 1;
			pq.push({ now - 1, nowSeconds + 1 });
		}

		if (2 * now < k + 2 && nowSeconds < dist[2 * now]) {
			dist[2 * now] = nowSeconds;
			pq.push({ 2 * now, nowSeconds });
		}
	}

	cout << dist[k] << '\n';

	return 0;
}

