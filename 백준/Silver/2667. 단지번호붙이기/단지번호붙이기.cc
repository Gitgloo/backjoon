#include <iostream>
#include <queue>;
#include <algorithm>
using namespace std;

bool map[27][27] = { {0} };

struct point {
	int r, c;
};

int main(void) {
	int n, dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0 ,-1 };
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string line;

		cin >> line;
		for (int j = 1; j <= n; j++) {
			*(*(map + i) + j) = line[j - 1] == '1';
		}
	}

	queue<point> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!*(*(map + i) + j)) continue;

			int size = 0;

			q.push({ i, j });
			*(*(map + i) + j) = false;

			while (q.size()) {
				point now = q.front();
				size++;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nextR = now.r + *(dr + k), nextC = now.c + *(dc + k);

					if (!*(*(map + nextR) + nextC)) continue;

					*(*(map + nextR) + nextC) = false;
					q.push({ nextR, nextC });
				}
			}

			pq.push(size);
		}
	}

	cout << pq.size() << '\n';
	while (pq.size()) {
		cout << pq.top() << '\n';
		pq.pop();
	}



	return 0;
}