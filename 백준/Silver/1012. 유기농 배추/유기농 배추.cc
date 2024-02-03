#include <iostream>
#include <queue>;
#include <algorithm>
using namespace std;

bool map[52][52] = { {0} };

struct point {
	int r, c;
};

int main(void) {
	int t, n, m, k, count, dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0 ,-1 };
	queue<point> q;

	cin >> t;
	while (t--) {
		cin >> m >> n >> k;

		while (k--) {
			int a, b;

			cin >> a >> b;
			*(*(map + b + 1) + a + 1) = 1;
		}

		count = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!*(*(map + i) + j)) continue;
				q.push({ i, j });
				*(*(map + i) + j) = false;
				count++;

				while (q.size()) {
					point now = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nextR = now.r + *(dr + k), nextC = now.c + *(dc + k);

						if (!*(*(map + nextR) + nextC)) continue;

						*(*(map + nextR) + nextC) = false;
						q.push({ nextR, nextC });
					}
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}