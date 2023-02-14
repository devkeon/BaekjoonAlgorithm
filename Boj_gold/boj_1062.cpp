#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k, alphabet = 0b1000'0010'0001'0000'0101, ans[1] = { 0 };
vector<int> words;

void word(int cnt,int alphabet, int index) {
	if (cnt > 0) {
		for (int i = index; i < 26; i++) {
			if ((alphabet & (1 << i)) == 0) {
				alphabet |= (1 << i);	
				word(cnt - 1, alphabet, i);
				alphabet &= ~(1 << i);
			}
		}
	}
	else {
		int tmpans = 0;
		for (int j = 0; j < n; j++) {
			if ((words[j] & alphabet) == words[j]) {
				tmpans += 1;
			}
		}
		ans[0] = max(ans[0], tmpans);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		int word_bit = 0;
		for (int j = 0; j < tmp.length(); j++) {
			int k = tmp[j] - 'a';
			word_bit |= (1 << k);
		}
		words.push_back(word_bit);
	}

	if (k < 5)
		cout << 0 << "\n";
	else if (k == 26)
		cout << n << "\n";
	else {
		word(k - 5, alphabet, 0);
		cout << ans[0];
	}

	return 0;
}
