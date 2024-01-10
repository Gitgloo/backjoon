#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	map<string, int> mapByName;
	map<int, string> mapByNum;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		mapByName.insert({ name, i });
		mapByNum.insert({ i, name });
	}

	while (m--) {
		string temp;
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9') {
			cout << mapByNum.find(stoi(temp))->second << '\n';
		} else {
			cout << mapByName.find(temp)->second << '\n';
		}
	}

	return 0;
}