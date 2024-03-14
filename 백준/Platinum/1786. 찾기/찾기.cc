#include <iostream>
#include <string>
#include <vector>

#define MAX_M 1000000

using namespace std;

void input();
void solve();

string text, pattern;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	input();
	solve();

	return 0;
}

void makeFailure(vector<int>& pi) {

	int start = 1, matched = 0, patternLen = pattern.size();

	while (start + matched < patternLen) {
		if (pattern[start + matched] == pattern[matched]) {
			pi[start + matched] = matched + 1;
			matched++;
		} else {
			if (matched == 0) {
				start++;
			} else {
				start += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

void kmp(vector<int>& finds, vector<int>& pi) {
	int start = 0, matched = 0, textLen = text.size(), patternLen = pattern.size();

	while (start <= textLen - patternLen) {
		if (matched < patternLen && text[start + matched] == pattern[matched]) {
			matched++;
			if (matched == patternLen) {
				finds.push_back(start + 1);
			}
		} else {
			if (matched == 0) {
				start++;
			} else {
				start += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}

void solve() {
	vector<int> pi(pattern.size());
	vector<int> finds;

	makeFailure(pi);
	kmp(finds, pi);

	cout << finds.size() << '\n';
	for (int index : finds) {
		cout << index << ' ';
	}
	cout << '\n';
}

void input() {
	getline(cin, text, '\n');
	getline(cin, pattern, '\n');
}