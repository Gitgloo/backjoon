#include <iostream>

using namespace std;

int recur(string& word, int left, int right) {
	if (left >= right)
		return 1;
	if (word[left] != word[right])
		return -1;
	int ret = recur(word, left + 1, right - 1);
	if (ret > 0)
		return ret + 1;
	return ret - 1;
}

void checkPalindrome(string& word) {
	int ret = recur(word, 0, word.length() - 1);
	if (ret > 0)
		cout << 1 << ' ' << ret << '\n';
	else
		cout << 0 << ' ' << -ret << '\n';
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	while (n--) {
		string word;

		cin >> word;
		checkPalindrome(word);
	}

	return 0;
}