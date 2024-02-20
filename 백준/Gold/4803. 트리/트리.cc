#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> childVector;

bool recur(int parent, int child);

int main(void) {
	int test = 1;

	while (true) {
		int n, m, treeCount = 0;

		cin >> n >> m;
		if (n == 0)
			break;

		childVector = vector<vector<int>>(n + 1, vector<int>(0));
		visited = vector<bool>(n + 1, false);
		while (m--) {
			int a, b;

			cin >> a >> b;
			childVector[a].push_back(b);
			childVector[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i])
				continue;

			if (recur(0, i))
				treeCount++;
		}

		cout << "Case " << test++;

		if (treeCount > 1) {
			cout << ": A forest of " << treeCount << " trees.\n";
		} else if (treeCount) {
			cout << ": There is one tree.\n";
		} else {
			cout << ": No trees.\n";
		}
	}

	return 0;
}

bool recur(int parent, int child) {
	if (visited[child]) {
		return false;
	}

	bool ret = true;

	visited[child] = true;

	vector<int> childs = childVector[child];
	for (int nowChild : childs) {
		if (nowChild == parent)
			continue;
		if (!recur(child, nowChild)) {
			ret = false;
		}
	}

	return ret;
}