#include <iostream>
#include <queue>

using namespace std;

struct point {
	int r, c, h;
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, h, day{ -1 }, total{ 0 }, count{ 0 }, *** map, dr[6] = { -1,0,1,0,0,0 }, dc[6] = { 0,1,0,-1,0,0 }, dh[6] = { 0,0,0,0,1,-1 };
	queue<point> q;

	cin >> m >> n >> h;

	map = new int** [h + 2];

	for (int i = 0; i < h + 2; i++) {
		*(map + i) = new int*[n + 2];
		for (int j = 0; j < n + 2; j++) {
			*(*(map + i) + j) = new int[m + 2];
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			*(*(*(map + i) + j)) = -1;
			*(*(*(map + i) + j) + m + 1) = -1;
		}

		for (int j = 1; j <= m; j++) {
			*(*(*(map + i)) + j) = -1;
			*(*(*(map + i) + n + 1) + j) = -1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			*(*(*(map)+i) + j) = -1;
			*(*(*(map + h + 1)+i) + j) = -1;
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				int temp;

				cin >> temp;
				*(*(*(map + i) + j) + k) = temp;

				if (temp == 1) {
					q.push({ j,k,i });
				}

				if (temp != -1) {
					total++;
				}
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
			for (int j = 0; j < 6; j++) {
				int nextR = now.r + dr[j], nextC = now.c + dc[j], nextH = now.h + dh[j];

				if (*(*(*(map + nextH) + nextR) + nextC) == 0) {
					*(*(*(map + nextH) + nextR) + nextC) = 1;
					q.push({ nextR, nextC, nextH });
				}
			}
		}
	}

	cout << (count == total ? day : -1) << '\n';

	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			delete[] *(*(map + i) + j);
		}
		delete[] *(map + i);
	}
	delete[] map;

	return 0;
}