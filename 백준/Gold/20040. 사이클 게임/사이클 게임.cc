#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

bool unionParents(int a, int b);
int findParent(int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, ans{ 0 };

	cin >> n;

	parents.reserve(n);
	for (int i = 0; i < n; i++) {
		parents.push_back(i);
	}

	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;

		cin >> a >> b;
		if (unionParents(a, b)) {
			ans = i;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}

bool unionParents(int a, int b) {
	int parentA = findParent(a);
	int parentB = findParent(b);

	if (parentA != parentB) {
		parents[parentA] = b;
		return false;
	}

	return true;
}

int findParent(int n) {
	int parent = parents[n];

	if (parent == n) {
		return n;
	}

	parent = findParent(parent);
	parents[n] = parent;

	return parent;
}
