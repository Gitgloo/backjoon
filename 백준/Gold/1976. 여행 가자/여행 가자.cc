#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;

int findParent(int n);
void unionParent(int a, int b);
bool checkSameParent(int a, int b);

int main(void) {
	int n, m, temp, parent;

	cin >> n >> m;
	parents.reserve(n + 1);
	for (int i = 0; i <= n; i++) {
		parents.push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp;

			cin >> temp;
			if (temp) {
				unionParent(i, j);
			}
		}
	}

	cin >> temp;
	parent = findParent(temp);
	while (--m) {
		cin >> temp;
		if (parent != findParent(temp)) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}

bool checkSameParent(int a, int b) {
	return findParent(a) == findParent(b);
}

void unionParent(int a, int b) {
	int parentA = findParent(a);
	if (parents[b] != b) {
		unionParent(parentA, parents[b]);
	} else {
		parents[b] = parentA;
	}
}

int findParent(int n) {
	if (parents[n] == n)
		return n;
	int parent = findParent(parents[n]);
	parents[n] = parent;
	return parent;
}