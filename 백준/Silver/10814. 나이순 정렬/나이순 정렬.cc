#include <iostream>
#include <algorithm>

using namespace std;

typedef struct s_info {
	int age;
	string name;
	int index;
}info;

bool compareInfo(info a, info b);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;

	info* arr = new info[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].index = i;
	}

	sort(arr, arr + n, compareInfo);

	for (int i = 0; i < n; i++) {
		cout << arr[i].age << ' ' << arr[i].name << '\n';
	}

	delete[] arr;

	return 0;
}

bool compareInfo(info a, info b) {
	if (a.age == b.age) {
		return a.index < b.index;
	}
	return a.age < b.age;
}