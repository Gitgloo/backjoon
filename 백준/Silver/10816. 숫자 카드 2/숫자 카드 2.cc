#include <iostream>
#include <map>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	map<int, int> saveMap;

	cin >> n;
	while (n--) {
		int temp;
		
		cin >> temp;
		saveMap[temp]++;
	}

	cin >> m;
	while (m--) {
		int temp;

		cin >> temp;
		cout << saveMap[temp] << ' ';
	}

	return 0;
}