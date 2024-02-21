#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

void unionFunc(int a, int b);
bool checkFunc(int a, int b);
int findParent(int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;
	parents.reserve(n + 1);
	for (int i = 0; i <= n; i++) {
		parents.push_back(i);
	}

	while (m--) {
		int c, a, b;
		
		cin >> c >> a >> b;
		if (c == 0) {
			unionFunc(a, b);
		} else {
			cout << (checkFunc(a, b) ? "YES\n" : "NO\n");
		}
	}
	

	return 0;
}

void unionFunc(int a, int b) {
	int parentA = findParent(a);

	if (parents[b] != b) {
		unionFunc(parentA, parents[b]);
	}
	parents[b] = parentA;
}

bool checkFunc(int a, int b) {
	int parentA = findParent(a);
	int parentB = findParent(b);

	return parentA == parentB;
}

int findParent(int n) {
	if (parents[n] != n)
		return findParent(parents[n]);
	return n;
}