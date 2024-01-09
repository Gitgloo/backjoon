#include <iostream>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

bool comparePoint(point a, point b);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	point* arr = new point[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	sort(arr, arr + n, comparePoint);

	for (int i = 0; i < n; i++) {
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}

	delete arr;

	return 0;
}

bool comparePoint(point a, point b) {
	if (a.x > b.x)
		return 0;
	else if (a.x < b.x)
		return 1;
	
	return a.y < b.y;
}