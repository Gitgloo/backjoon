#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

typedef struct s_memory {
	string word;
	int count;
}memory;

int compareMemory(memory a, memory b);

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	map<string, int> count;

	cin >> n >> m;
	while (n--) {
		string word;

		cin >> word;
		if (word.length() >= m)
			count[word]++;
	}

	memory* arr = new memory[count.size()];
	int index = 0;
	for (map<string, int>::iterator iter = count.begin(); iter != count.end(); iter++) {
		memory temp;
		temp.word = iter->first;
		temp.count = iter->second;
		arr[index++] = temp;
	}

	sort(arr, arr + count.size(), compareMemory);

	for (int i = 0; i < count.size(); i++) {
		cout << arr[i].word << '\n';
	}

	delete[] arr;


	return 0;
}

int compareMemory(memory a, memory b) {
	if (a.count == b.count) {
		if (a.word.length() == b.word.length()) {
			return a.word.compare(b.word) < 0;
		}
		return a.word.length() > b.word.length();
	}
	return a.count > b.count;
}