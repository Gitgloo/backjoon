#include <iostream>
#include <queue>

using namespace std;

struct point {
	int r, c;
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, day{ -1 }, total{ 0 }, count{ 0 }, ** map, dr[4] = { -1,0,1,0 }, dc[4] = { 0,1,0,-1 };
	queue<point> q;

	cin >> m >> n;

	map = new int* [n + 2];
	for (int i = 0; i < n + 2; i++) {
		*(map + i) = new int[m + 2];
	}

	for (int i = 1; i <= m; i++) {
		*(*map + i) = -1;
		*(*(map + n + 1) + i) = -1;
	}

	for (int i = 1; i <= n; i++) {
		*(*(map + i)) = -1;
		*(*(map + i) + m + 1) = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;

			cin >> temp;
			*(*(map + i) + j) = temp;

			if (temp == 1) {
				q.push({ i,j });
			}

			if (temp != -1) {
				total++;
			}
		}
	}

	while (true) {
		int	stepSize = q.size();
		if (!stepSize)
			break;

		day++;
		count += stepSize;
		for (int i = 0; i < stepSize; i++) {
			point now = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nextR = now.r + dr[j], nextC = now.c + dc[j];

				if (*(*(map + nextR) + nextC) == 0) {
					*(*(map + nextR) + nextC) = 1;
					q.push({ nextR, nextC });
				}
			}
		}
	}

	cout << (count == total ? day : -1) << '\n';

	for (int i = 0; i < n + 2; i++) {
		delete[] *(map + i);
	}
	delete[] map;

	return 0;
}