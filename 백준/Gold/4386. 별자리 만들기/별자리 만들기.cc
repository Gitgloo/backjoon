#include <iostream>
#include <queue>
#include <math.h>

#define ABS(x) ((x) < 0 ? -(x) : (x))

using namespace std;

struct star {
	double x, y;
};

struct edge {
	int next;
	double weight;
};

bool operator<(edge a, edge b) {
	return a.weight > b.weight;
}

void getInput();
void solve();
double getWeight(int a, int b);

int n;
star arr[100];

int main(void) {
	

	cin >> n;
	getInput();
	solve();

	return 0;
}

void solve() {
	int now = 0, repeat = n;
	double sum = 0.0;
	priority_queue<edge> pq;
	int visited[100] = { 0 };

	while (repeat--) {
		visited[now] = true;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				pq.push({ i, getWeight(now, i) });
			}
		}

		while (pq.size()) {
			if (!visited[pq.top().next]) {
				now = pq.top().next;
				sum += pq.top().weight;
				break;
			}
			pq.pop();
		}
	}

	cout << sum << endl;
}

double getWeight(int a, int b) {
	return sqrt(pow(ABS(arr[a].x - arr[b].x), 2) + pow(ABS(arr[a].y - arr[b].y), 2));
}

void getInput() {
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
}