#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> cnt_alphabet;
vector<char> alphabet;

void cnt(vector<int> &cnt_alphabet, vector<char> &alphabet, string str) {  //count all string alphabets
	int check = 0;
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] == str[i + 1]) {
			check++;
		}
		else {
			check += 1;
			alphabet.push_back(str[i]);
			cnt_alphabet.push_back(check);
			check = 0;
		}
	}
	check++;
	alphabet.push_back(str[str.length() - 1]);
	cnt_alphabet.push_back(check);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string before_pal;
	cin >> before_pal;

	sort(before_pal.begin(), before_pal.end());  //sort to count alphabet easily
	cnt(cnt_alphabet, alphabet, before_pal);

	int flag = -1;
	string ans;

	for (int i = 0; i < alphabet.size(); i++) {  //make a palindrome
		if (cnt_alphabet[i] % 2 == 1) {
			if (flag != -1) {  //if there is more than two odd num alphabet it can't be
				flag = -3;
				break;
			}
			else {
				flag = i;
				for (int j = 0; j < cnt_alphabet[i] / 2; j++) {  //add half of the alphabet except remainder
					ans += alphabet[i];
				}
				cnt_alphabet[i] /= 2;  //make it half to make palindrome (add reverse) easier
			}
		}
		else {
			for (int j = 0; j < cnt_alphabet[i] / 2; j++) {
				ans += alphabet[i];
			}
			cnt_alphabet[i] /= 2;
		}
	}
	if (flag != -1) {  //add odd num of alphabet (it nust be one)
		ans += alphabet[flag];
	}
	for (int i = alphabet.size() - 1; i >= 0; i--) {  //add it reverse and make it palindrome (just add it)
		for (int j = 0; j < cnt_alphabet[i]; j++) {
			ans += alphabet[i];
		}
	}
	if (flag == -3)
		cout << "I'm Sorry Hansoo";
	else
		cout << ans;

	return 0;
}
