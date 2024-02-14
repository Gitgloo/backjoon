#include <iostream>
#include <vector>
#include <stack>

#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

int main(void) {
	int n, w;

	cin >> n >> w;
	vector<pair<int, int>> events(w + 2);
	events[0].first = 1;
	events[0].second = 1;
	events[1].first = n;
	events[1].second = n;
	for (int i = 2; i < w + 2; i++) {
		cin >> events[i].first >> events[i].second;
	}

	vector<vector<int>> dp(w);
	for (int i = 0; i < w; i++) {
		dp[i].resize(i + 2);
	}
	dp[0][0] = n - events[2].first + n - events[2].second;
	dp[0][1] = events[2].first - 1 + events[2].second - 1;
	
	vector<int> orders(w + 2);
	orders[0] = 1;
	orders[1] = 0;
	for (int i = 1; i < w; i++) {
		pair<int, int> now = events[i + 2];
		pair<int, int> before = events[i + 1];
		int diff = ABS(now.first - before.first) + ABS(now.second - before.second);
		int min = 2147483647;
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + diff;
			
			int temp = dp[i - 1][j] + ABS(now.first - events[j].first) + ABS(now.second - events[j].second);
			if (min > temp) {
				min = temp;
				orders[i + 1] = (orders[j] + 1) % 2;
			}
		}
		dp[i][i + 1] = min;
	}

	int nowIndex = 0;
	int minAns = dp[w - 1][0];
	for (int i = 0; i <= w; i++) {
		if (minAns > dp[w - 1][i]) {
			minAns = dp[w - 1][i];
			nowIndex = i;
		}
	}
	cout << minAns << '\n';
	stack<int> order;
	order.push(orders[nowIndex]);
	for (int i = w - 1; i > 0; i--) {
		pair<int, int> now = events[i + 2];
		
		if (nowIndex == i + 1) {
			int nowValue = dp[i][nowIndex];
			for (int j = 0; j < nowIndex; j++) {
				if (nowValue == dp[i - 1][j] + ABS(now.first - events[j].first) + ABS(now.second - events[j].second)) {
					nowIndex = j;
					break;
				}
			}
		}
		order.push(orders[nowIndex]);
	}

	while (order.size()) {
		cout << order.top() + 1 << '\n';
		order.pop();
	}	

	return 0;
}