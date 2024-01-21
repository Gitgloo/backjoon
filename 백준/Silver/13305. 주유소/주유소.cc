#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, minCost;
	long long int sum{ 0 }, temp{ 0 };

	cin >> n;
	int* dist = new int[n - 1];
	int* cost = new int[n];
	
	for (int i = 0; i < n - 1; i++) {
		cin >> dist[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	minCost = cost[0];
	for (int i = 1; i < n; i++) {
		temp += dist[i - 1];
		if (cost[i] < minCost) {
			sum += temp * minCost;
			temp = 0;
			minCost = cost[i];
		}
	}
	sum += temp * minCost;

	cout << sum << endl;

	delete[] dist;
	delete[] cost;

	return 0;
}