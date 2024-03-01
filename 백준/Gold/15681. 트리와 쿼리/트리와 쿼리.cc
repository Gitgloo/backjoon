#include <iostream>
#include <vector>

using namespace std;

int n, r, q, dp[100001];
vector<int> edgeArray[100001];

void initInput();
void solve();
void queryInput();

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	initInput();
	solve();
	queryInput();

	return 0;
}

int dfs(int parent, int now) {
	int childNodes = 1;
	vector<int> edges = edgeArray[now];

	for (int child : edges) {
		if (child == parent)
			continue;
		childNodes += dfs(now, child);
	}

	return dp[now] = childNodes;
}

void solve() {
	int a = 0;
	dp[r] = dfs(0, r);
}

void queryInput() {
	while (q--) {
		int u;

		cin >> u;
		cout << dp[u] << '\n';
	}
}

void initInput() {
	cin >> n >> r >> q;

	for (int i = 1; i < n; i++) {
		int u, v;

		cin >> u >> v;
		edgeArray[u].push_back(v);
		edgeArray[v].push_back(u);
	}
}