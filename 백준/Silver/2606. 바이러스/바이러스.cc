#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> edgeVector[101]);

int main(void) {
	int n, edgeCount;
	vector<int> edgeVector[101];

	cin >> n >> edgeCount;
	while (edgeCount--) {
		int a, b;

		cin >> a >> b;
		(edgeVector + a)->push_back(b);
		(edgeVector + b)->push_back(a);
	}

	cout << bfs(edgeVector) << '\n';

	return 0;
}

int bfs(vector<int> edgeVector[101]) {
	int count = -1;
	queue<int> q;
	bool visited[101] = { false };

	visited[1] = true;
	q.push(1);

	while (q.size()) {
		int now = q.front();
		count++;
		vector<int> edges = *(edgeVector + now);
		for (int i = 0; i < edges.size(); i++) {
			int next = edges[i];
			if (!*(visited + next)) {
				*(visited + next) = true;
				q.push(next);
			}
		}
		q.pop();
	}

	return count;
}