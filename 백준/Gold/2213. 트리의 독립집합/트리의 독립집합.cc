#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_N 10001

using namespace std;

int n, weight[MAX_N], dp[MAX_N], parents[MAX_N];
bool flag[MAX_N];
vector<int> edgeArray[MAX_N];
vector<int> setNodes;

void makeTree(int now);
void findSet(int now);

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

	parents[1] = 0;
	makeTree(1);

	int max = 0;
	int ansIndex = 1;
	for (int i = 0; i <= n; i++) {
		if (max < dp[i]) {
			ansIndex = i;
			max = dp[i];
		}
	}

	findSet(ansIndex);
	sort(setNodes.begin(), setNodes.end());

	cout << dp[ansIndex] << '\n';
	for (int node : setNodes) {
		cout << node << ' ';
	}
	cout << '\n';

	return 0;
}

void makeTree(int now) {
	int parent = parents[now];
	int withNow = weight[now];
	int withoutNow = 0;

	for (int child : edgeArray[now]) {
		if (child == parent)
			continue;

		parents[child] = now;
		makeTree(child);
		withoutNow += dp[child];

		for (int grandChild : edgeArray[child]) {
			if (grandChild == now)
				continue;
			withNow += dp[grandChild];
		}
	}

	if (withNow > withoutNow) {
		dp[now] = withNow;
		flag[now] = true;
	} else {
		dp[now] = withoutNow;
	}
}

void findSet(int now) {
	int parent = parents[now];

	if (flag[now]) {
		setNodes.push_back(now);
		for (int child : edgeArray[now]) {
			if (child == parent)
				continue;

			for (int grandChild : edgeArray[child]) {
				if (grandChild == now)
					continue;
				findSet(grandChild);
			}
		}
	} else {
		for (int child : edgeArray[now]) {
			if (child == parent)
				continue;

			findSet(child);
		}
	}
}