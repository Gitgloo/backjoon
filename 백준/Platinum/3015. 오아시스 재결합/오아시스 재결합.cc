#include <iostream>
#include <stack>

using namespace std;

struct node {
	int height, count;
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, first, total{ 1 };
	long long int count = 0;
	stack<node> s;

	cin >> n >> first;
	s.push({ first, 1 });
	while (--n) {
		int temp, top = s.top().height, plus{ 1 };

		cin  >> temp;

		if (temp < top) {
			s.push({ temp, 1 });
		} else {
			plus = total;

			while (s.size() && s.top().height < temp) {
				total -= s.top().count;
				s.pop();
			}

			plus -= total;

			if (s.size() && s.top().height == temp) {	
				plus += s.top().count++;
			} else {
				s.push({ temp, 1 });
			}

			if (s.size() > 1) {
				plus++;
			}
		}
		total++;
		count += plus;
	}

	cout << count << '\n';

	return 0;
}