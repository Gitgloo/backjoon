#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	set<int> s;
	map<int, int> m;

	cin >> n;
	int* save = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> save[i];
		s.insert(save[i]);
	}

	int under = 0;
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++, under++) {
		m.insert({ *iter, under });
	}

	for (int i = 0; i < n; i++) {
		cout << m.find(save[i]) -> second << ' ';
	}

	cout << endl;

	delete[] save;

	return 0;
}