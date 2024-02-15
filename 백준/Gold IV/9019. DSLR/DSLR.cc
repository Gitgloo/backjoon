#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
	int T;
	char map[4] = { 'D','S','L','R' };
	stack<char> sequence;

	cin >> T;
	while (T--) {
		int a, b;
		vector<pair<int, int>> dp(10001, {-1, 0});
		queue<int> q1;

		cin >> a >> b;
		dp[a].first = 0;
		q1.push(a);
		while (true) {
			int n = q1.front();
			
			if (n == b)
				break;
			q1.pop();

			int arr[4];
			arr[0] = 2 * n % 10000;
			arr[1] = (n - 1 + 10000) % 10000;
			arr[2] = (n % 1000) * 10 + n / 1000;
			arr[3] = n % 10 * 1000 + (n / 10);
			for (int i = 0; i < 4; i++) {
				int after = arr[i];
				if (dp[after].first == -1) {
					dp[after].first = n;
					dp[after].second = i;
					q1.push(after);
				}
			}
		}

		int now = b;
		while (now != a) {
			sequence.push(map[dp[now].second]);
			now = dp[now].first;
		}

		while (sequence.size()) {
			cout << sequence.top();
			sequence.pop();
		}
		cout << '\n';
	}

	return 0;
}