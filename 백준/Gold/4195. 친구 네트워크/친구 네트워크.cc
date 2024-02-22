#include <iostream>
#include <map>

using namespace std;

int parents[200000];
int counts[200000];
int nameIndex;
map<string, int> m;

int getIndex(string& name);
void unionParents(int a, int b);
int findParent(int n);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;

	cin >> T;
	while (T--) {
		int F;

		m.clear();
		nameIndex = 0;

		cin >> F;
		while (F--) {
			string name1, name2;
			int friend1, friend2;

			cin >> name1 >> name2;
			
			friend1 = getIndex(name1);
			friend2 = getIndex(name2);

			unionParents(friend1, friend2);
		}
	}

	return 0;
}

void unionParents(int a, int b) {
	int parentA = findParent(a);
	int parentB = findParent(b);

	if (parentA != parentB) {
		parents[parentA] = parentB;
		counts[parentB] += counts[parentA];
	}
	
	cout << counts[parentB] << '\n';
}

int findParent(int n) {
	int parent = parents[n];      

	if (parent == n)
		return n;
	parent = findParent(parent);
	parents[n] = parent;

	return parent;
}

int getIndex(string& name) {
	map<string, int>::iterator iter = m.find(name);
	if (iter == m.end()) {
		m[name] = nameIndex;
		parents[nameIndex] = nameIndex;
		counts[nameIndex] = 1;

		return nameIndex++;
	}

	return iter->second;
}