#include <iostream>
#include <vector>
#include <algorithm>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define START 1

using namespace std;

struct Edge {
	int next, dist;
};

vector<vector<Edge>> childs;
vector<bool> visited;
int maxLength = 0;

bool compare(int a, int b) {
	return a > b;
}

int recur(int now);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	childs.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int p, c, w;

		cin >> p >> c >> w;
		childs[p].push_back({ c,w });
	}

	visited[START] = true;
	recur(START);
	cout << maxLength << '\n';

	return 0;
}

int recur(int now) {
	vector<Edge> nowChilds = childs[now];
	vector<int> lengths(2, 0);
	for (int i = 0; i < nowChilds.size(); i++) {
		Edge child = nowChilds[i];
		if (!visited[child.next]) {
			visited[child.next] = true;
			lengths.push_back(child.dist + recur(child.next));
		}
	}

	sort(lengths.begin(), lengths.end(), compare);
	maxLength = MAX(maxLength, lengths[0] + lengths[1]);
	return lengths[0];
}