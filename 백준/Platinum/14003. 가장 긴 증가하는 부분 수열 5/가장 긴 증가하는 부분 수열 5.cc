#include <iostream>
#include <vector>
#include <stack>

#define INF 1001
#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
	int n, input, max{ 0 };
	vector<int> arr, dp, before;
	stack<int> ans;

	cin >> n;
	arr.resize(n + 1, INF);
	before.resize(n + 1);
	dp.resize(n + 1, n);
	arr[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		int left = 0, right = max;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (arr[dp[mid]] >= arr[i]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		dp[left] = i;
		before[i] = dp[right];
		max = MAX(max, left);
	}

	max = dp[max];
	while (arr[max] != 0) {
		ans.push(arr[max]);
		max = before[max];
	}

	cout << ans.size() << '\n';
	while (ans.size()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';

	return 0;
}