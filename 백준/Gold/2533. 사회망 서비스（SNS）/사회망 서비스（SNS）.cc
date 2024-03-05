#include <iostream>
#include <vector>

#define MAX_N 1000000
#define MIN(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

int dp[MAX_N + 1][2];
vector<int> edgeArray[MAX_N + 1];

void makeTree(int parent, int now);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;

		cin >> u >> v;
		edgeArray[u].push_back(v);
		edgeArray[v].push_back(u);
	}

	makeTree(0, 1);

	if (dp[1][0] && dp[1][0] < dp[1][1]) {
		cout << dp[1][0] << '\n';
	} else {
		cout << dp[1][1] << '\n';
	}

	return 0;
}

void makeTree(int parent, int now) {
	vector<int>& edges = edgeArray[now];

	int childsWithZero = 0, childsWithOne = 1;
	for (int& child : edges) {
		if (child == parent)
			continue;

		makeTree(now, child);
		childsWithZero += dp[child][1];
		childsWithOne += MIN(dp[child][0], dp[child][1]);
	}

	dp[now][0] = childsWithZero;
	dp[now][1] = childsWithOne;
}