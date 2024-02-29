#include <iostream>
#include <queue>

#define MAX 200000

using namespace std;

struct road {
	int x, y, z;
};

struct roadCompare {
	bool operator()(road& a, road& b) {
		return a.z > b.z;
	}
};

int n, m, total, parents[MAX];
priority_queue<road, vector<road>, roadCompare> pq;

bool input();
void solve();

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (input()) {
		solve();
	}

	return 0;
}

int getParent(int n) {
	if (parents[n] < 0)
		return n;
	parents[n] = getParent(parents[n]);
	return parents[n];
}

void doUnion(int x, int y) {
	parents[y] += parents[x];
	parents[x] = y;
}

bool unionRoad(int x, int y) {
	int parentX = getParent(x), parentY = getParent(y);

	if (parentX == parentY)
		return false;

	if (parents[parentX] < parents[parentY]) {
		doUnion(parentX, parentY);
	} else {
		doUnion(parentY, parentX);
	}
	return true;
}

void solve() {
	while (true) {
		road now = pq.top();

		pq.pop();

		if (unionRoad(now.x, now.y)) {
			total -= now.z;
			if (--m == 1)
				break;
		}
	}

	cout << total << '\n';
}

bool input() {

	cin >> m >> n;

	if (m == 0 && n == 0)
		return false;

	for (int i = 0; i < m; i++) {
		parents[i] = -1;
	}

	pq = priority_queue<road, vector<road>, roadCompare>();

	total = 0;
	while (n--) {
		int x, y, z;

		cin >> x >> y >> z;
		pq.push({ x, y, z });
		total += z;
	}

	return true;
}