#include <iostream>
#include <algorithm>

using namespace std;

typedef struct s_meeting {
	int start, end;
} meeting;

bool compare(meeting a, meeting b) {
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, count{ 0 };

	cin >> n;
	meeting* arr = new meeting[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].end;
	}
	
	sort(arr, arr + n, compare);

	int endTime = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].start >= endTime) {
			count++;
			endTime = arr[i].end;
		}
	}

	cout << count << '\n';

	return 0;
}