#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 10001

using namespace std;

int n, weight[MAX_N], dp[MAX_N];
vector<int> edgeArray[MAX_N];

void makeTree(int parent, int now);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i];
	}

	for (int i = 1; i < n; i++) {
		int a, b;

		cin >> a >> b;
		edgeArray[a].push_back(b);
		edgeArray[b].push_back(a);
	}

	makeTree(0, 1);

	cout << dp[1] << '\n';

	return 0;
}

void makeTree(int parent, int now) {
	int withNow = weight[now];
	int withoutNow = 0;

	for (int child : edgeArray[now]) {
		if (child == parent)
			continue;

		makeTree(now, child);
		withoutNow += dp[child];

		for (int grandChild : edgeArray[child]) {
			if (grandChild == now)
				continue;
			withNow += dp[grandChild];
		}
	}

	if (withNow > withoutNow) {
		dp[now] = withNow;
	}
	else {
		dp[now] = withoutNow;
	}
}