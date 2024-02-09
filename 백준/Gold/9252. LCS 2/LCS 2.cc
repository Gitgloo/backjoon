#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node {
	int i, j;
	char ch;
};

int main(void) {
	string a, b, blank{ "" };
	vector<vector<int>> dp;
	vector<vector<node>> saveBefore;
	stack<char> ans;

	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	dp.resize(a.length() + 1, vector<int>(b.length() + 1, 0));
	saveBefore.resize(a.length() + 1, vector<node>(b.length() + 1, { 0, 0, 0 }));

	for (int i = 1; i < a.length(); i++) {
		for (int j = 1; j < b.length(); j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				saveBefore[i][j] = { i - 1, j - 1, a[i]};
			} else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					saveBefore[i][j] = saveBefore[i - 1][j];
				} else {
					dp[i][j] = dp[i][j - 1];
					saveBefore[i][j] = saveBefore[i][j - 1];
				}
			}
		}
	}

	cout << dp[a.length() - 1][b.length() - 1] << '\n';
	
	node now = saveBefore[a.length() - 1][b.length() - 1];
	while (now.ch != 0) {
		ans.push(now.ch);
		now = saveBefore[now.i][now.j];
	}
	while (ans.size()) {
		cout << ans.top();
		ans.pop();
	}
	cout << '\n';
	return 0;
}