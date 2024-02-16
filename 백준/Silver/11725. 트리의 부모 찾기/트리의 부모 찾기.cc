#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> nodes;
vector<int> parents;

void findChilds(int now);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	nodes.resize(n + 1);
	parents.resize(n + 1);

	for (int i = 1; i < n; i++) {
		int a, b;

		cin >> a >> b;
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	parents[0] = -1;
	findChilds(1);

	for (int i = 2; i <= n; i++) {
		cout << parents[i] << '\n';
	}

	return 0;
}

void findChilds(int now) {
	vector<int> childs = nodes[now];
	for (int child : childs) {
		if (parents[child] == 0) {
			parents[child] = now;
			findChilds(child);
		}
	}
}
