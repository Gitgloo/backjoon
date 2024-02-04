#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int n, m, visited[101] = { 0 }, board[101] = { 0 };
	queue<int> q;

	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int from, to;

		cin >> from >> to;
		*(board + from) = to;
	}

	q.push(1);

	while (q.size()) {
		int now = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			if (next <= 100 && !*(visited + next)) {
				*(visited + next) = *(visited + now) + 1;
				int boardMove = *(board + next);
				if (boardMove) {
					if (!*(visited + boardMove)) {
						*(visited + boardMove) = *(visited + next);
						q.push(*(board + next));
					}
				} else {
					q.push(next);
				}
			}
		}
	}

	cout << *(visited + 100) << '\n';

	return 0;
}