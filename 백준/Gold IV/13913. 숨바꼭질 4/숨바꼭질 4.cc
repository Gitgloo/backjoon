#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int n, k;
	vector<int> dp(100001, -1);
	queue<int> q;

	cin >> n >> k;
	q.push(k);
	while (true) {
		int now = q.front();
		if (now == n)
			break;

		q.pop();
		if (now + 1 <= 100000 && dp[now + 1] == -1) {
			dp[now + 1] = now;
			q.push(now + 1);
		}
		if (now - 1 >= 0 && dp[now - 1] == -1) {
			dp[now - 1] = now;
			q.push(now - 1);
		}
		if (now % 2 == 0 && dp[now / 2] == -1) {
			dp[now / 2] = now;
			q.push(now / 2);
		}
	}

	int now = n;
	queue<int> q2;
	q2.push(now);
	while (now != k) {
		now = dp[now];
		q2.push(now);
	}

	cout << q2.size() - 1<< '\n';
	while (q2.size()) {
		cout << q2.front() << ' ';
		q2.pop();
	}
	cout << '\n';

	return 0;
}