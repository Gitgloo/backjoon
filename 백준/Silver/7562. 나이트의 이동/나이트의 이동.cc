#include <iostream>
#include <queue>

using namespace std;

struct point {
	int r, c;
};

bool isRange(int l, int r, int c);

int main(void) {
	int t, l, k, ans, dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 }, dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	bool** map;
	point start, end;
	queue<point> q;

	cin >> t;
	while (t--) {
		cin >> l >> start.r >> start.c >> end.r >> end.c;

		map = new bool* [l];
		for (int i = 0; i < l; i++) {
			*(map + i) = new bool[l]();
		}

		ans = -1;
		q.push(start);
		*(*(map + start.r) + start.c) = true;
		while (q.size()) {
			int stepSize = q.size();

			ans++;
			for (int i = 0; i < stepSize; i++) {
				point now = q.front();
				if (now.r == end.r && now.c == end.c) {
					cout << ans << '\n';
					q = queue<point>();
					break;
				}
				q.pop();
				for (int j = 0; j < 8; j++) {
					int nextR = now.r + dr[j], nextC = now.c + dc[j];

					if (isRange(l, nextR, nextC) && !*(*(map + nextR) + nextC)) {
						*(*(map + nextR) + nextC) = true;
						q.push({ nextR, nextC });
					}
				}
			}
		}

		for (int i = 0; i < l; i++) {
			delete[] * (map + i);
		}
		delete[] map;
	}

	return 0;
}

bool isRange(int l, int r, int c) {
	return r >= 0 && r < l && c >= 0 && c < l;
}