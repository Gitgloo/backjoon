#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	map<string, int> mapByName;

	cin >> n >> m;
	string* arr = new string[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		mapByName.insert({ arr[i], i });
	}

	while (m--) {
		string temp;
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9') {
			cout << arr[stoi(temp)] << '\n';
		} else {
			cout << mapByName.find(temp)->second << '\n';
		}
	}

	return 0;
}