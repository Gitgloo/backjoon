#include <iostream>
#include <queue>

using namespace std;

struct point {
	int r, c;
};

int main(void) {
	int n, m, dr[4] = { -1,0,1,0 }, dc[4] = { 0, 1, 0 ,-1 }, ans{ 0 };
	bool map[102][102] = { {0} };
	queue<point> q;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string line;

		cin >> line;
		for (int j = 1; j <= m; j++) {
			*(*(map + i) + j) = line[j - 1] == '1';
		}
	}

	q.push({ 1,1 });
	*(*(map + 1) + 1) = false;

	while (q.size()) {
		int nowStep = q.size();
		ans++;
		for (int k = 0; k < nowStep; k++) {
			point now = q.front();
			if (now.r == n && now.c == m) {
				cout << ans << endl;
				return 0;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nextR = now.r + dr[i], nextC = now.c + dc[i];

				if (*(*(map + nextR) + nextC)) {
					q.push({ nextR, nextC });
					*(*(map + nextR) + nextC) = false;
				}
			}
		}
	}

	return 0;
}