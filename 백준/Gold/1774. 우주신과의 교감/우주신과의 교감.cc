#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct point {
	int x, y;
};

struct edge {
	int from, to;
	long long weight;
};

bool operator<(edge a, edge b) {
	return a.weight > b.weight;
}

int n, m;
int parents[1001];
point arr[1001];

bool unionParent(int a, int b);
void solve();

int main(void) {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parents[i] = -1;
		cin >> arr[i].x >> arr[i].y;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		
		cin >> a >> b;
		unionParent(a, b);
	}

	solve();

	return 0;
}

long long getWeight(int a, int b) {
	return pow(arr[a].x - arr[b].x, 2) + pow(arr[a].y - arr[b].y, 2);
}

void solve() {
	double sum = 0;
	priority_queue<edge> pq;

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pq.push({ i, j, getWeight(i, j) });
		}
	}

	while (pq.size()) {
		edge now = pq.top();

		pq.pop();
		if (unionParent(now.from, now.to)) {
			sum += sqrt(now.weight);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << sum << '\n';
}

int getParent(int n) {
	if (parents[n] < 0)
		return n;
	parents[n] = getParent(parents[n]);
	return parents[n];
}

void doUnion(int a, int b) {
	parents[a] += parents[b];
	parents[b] = a;
}

bool unionParent(int a, int b) {
	int parentA = getParent(a), parentB = getParent(b);

	if (parentA == parentB) {
		return false;
	} else if (parents[parentA] < parents[parentB]) {
		doUnion(parentA, parentB);
	} else {
		doUnion(parentB, parentA);
	}

	return true;
}