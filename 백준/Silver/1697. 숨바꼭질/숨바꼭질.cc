#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int n, k, ans{ -1 };
	bool visited[100001] = { false };
	queue<int> q;

	cin >> n >> k;
	
	q.push(n);
	*(visited + n) = true;
	
	while (q.size()) {
		int stepSize = q.size();
		ans++;
		for (int i = 0; i < stepSize; i++) {
			int now = q.front();
			if (now == k) {
				cout << ans << '\n';
				return 0;
			}
			q.pop();

			if (now + 1 <= 100000 && !*(visited + now + 1)) {
				*(visited + now + 1) = true;
				q.push(now + 1);
			}
			if (now - 1 >= 0 && !*(visited + now - 1)) {
				*(visited + now - 1) = true;
				q.push(now - 1);
			}
			if (2 * now <= 100000 && !*(visited + 2 * now)) {
				*(visited + 2 * now) = true;
				q.push(2 * now);
			}
		}
	}

	return 0;
}