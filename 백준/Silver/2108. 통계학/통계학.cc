#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, sum{ 0 }, arr[8001] = { 0 }, min{ -4001 }, max{ 4001 }, mid{ 0 }, maxCount{ 0 };
	set<int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;
		arr[temp + 4000]++;
	}

	while (!arr[++min + 4000]);
	while (!arr[--max + 4000]);

	int count = 0;
	for (int i = min; i <= max; i++) {
		sum += arr[i + 4000] * i;
		if (count < n / 2 + 1 && count + arr[i + 4000] >= n / 2 + 1) {
			mid = i;
		}
		count += arr[i + 4000];
		if (arr[i + 4000] > maxCount) {
			maxCount = arr[i + 4000];
			s.clear();
			s.insert(i);
		} else if (arr[i + 4000] == maxCount) {
			s.insert(i);
		}
	}

	int avg = round((double)sum / n);
	cout << avg << endl;
	cout << mid << endl;
	if (s.size() == 1) {
		cout << *s.begin() << endl;
	}
	else {
		cout << *(++s.begin()) << endl;
	}
	cout << max - min << endl;

	return 0;
}