#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void printDfs(int n, int v, vector<int> edgeArray[1001]);
void dfs(int n, int v, vector<int> edgeArray[1001], bool visited[1001]);
void printBfs(int n, int v, vector<int> edgeArray[1001]);

int main(void) {
	int n, m, v;
	vector<int> edgeArray[1001];

	cin >> n >> m >> v;
	while (m--) {
		int a, b;

		cin >> a >> b;
		(edgeArray + a)->push_back(b);
		(edgeArray + b)->push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort((edgeArray + i)->begin(), (edgeArray + i)->end());
	}

	printDfs(n, v, edgeArray);
	printBfs(n, v, edgeArray);

	return 0;
}

void printDfs(int n, int v, vector<int> edgeArray[1001]) {
	bool visited[1001] = { 0 };

	dfs(n, v, edgeArray, visited);
	cout << '\n';
}

void dfs(int n, int v, vector<int> edgeArray[1001], bool visited[1001]) {
	*(visited + v) = true;
	cout << v << ' ';

	vector<int> edges = *(edgeArray + v);
	for (int i = 0; i < edges.size(); i++) {
		int next = edges[i];

		if (!*(visited + next)) {
			dfs(n, next, edgeArray, visited);
		}
	}
}

void printBfs(int n, int v, vector<int> edgeArray[1001]) {
	bool visited[1001] = { 0 };
	queue<int> q;

	*(visited + v) = true;
	q.push(v);

	while (q.size()) {
		int now = q.front();
		cout << now << ' ';
		vector<int> edges = *(edgeArray + now);
		q.pop();
		for (int i = 0; i < edges.size(); i++) {
			int next = edges[i];

			if (!*(visited + next)) {
				*(visited + next) = true;
				q.push(next);
			}
		}
	}
	cout << '\n';
}