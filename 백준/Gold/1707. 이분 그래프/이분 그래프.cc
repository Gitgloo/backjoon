#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(int start);

vector<int> edgeArray[20001];
int teamCheck[20001];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
	int k;

	cin >> k;
	while (k--) {
		int v, e;
		bool result = true;

		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			edgeArray[i].clear();
		}

		for (int i = 1; i <= v; i++) {
			teamCheck[i] = -1;
		}

		while (e--) {
			int a, b;

			cin >> a >> b;
			edgeArray[a].push_back(b);
			edgeArray[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (teamCheck[i] == -1 && !bfs(i)) {
				result = false;
				break;
			}
		}

		cout << (result ? "YES\n" : "NO\n");
	}

	return 0;
}

bool bfs(int start) {
	int teamA = 0, teamB = 1;
	queue<int> q;
	q.push(start);
	teamCheck[start] = teamA;

	while (true) {
		int stepSize = q.size();
		if (stepSize == 0)
			break;
		teamA ^= 1;
		teamB ^= 1;
		for (int i = 0; i < stepSize; i++) {
			int now = q.front();
			
			q.pop();
			vector<int> edges = edgeArray[now];
			for (int i = 0; i < edges.size(); i++) {
				int next = edges[i];
				if (teamCheck[next] == teamB)
					return false;
				if (teamCheck[next] == -1) {
					teamCheck[next] = teamA;
					q.push(next);
				}
			}
		}
	}

	return true;
}