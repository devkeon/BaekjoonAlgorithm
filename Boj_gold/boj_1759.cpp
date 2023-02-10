#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int l, c;
char ch[15];
char vow[] = { 'a', 'e', 'i', 'o', 'u' };

bool find_vowel(char temp) {	//find vowel & return true or false
	for (int i = 0; i < 5; i++) {
		if (temp == vow[i])
			return true;
	}
	return false;
}

void bt(int vowel, int consonant, int len, string ans, int ind) {	//backtracking
	if (len == l) {
		if (vowel >= 1 && consonant >= 2) {
			cout << ans << "\n";
		}
	}
	 else if (c - ind >= l - len) {
		string tmp;
		tmp += ch[ind];
		if (find_vowel(ch[ind])) {
			bt(vowel + 1, consonant, len + 1, ans + tmp, ind + 1);	//accept alphabet that is vowel
		}
		else {
			bt(vowel, consonant + 1, len + 1, ans + tmp, ind + 1);	//accept alphabet that is consonant
		}
		bt(vowel, consonant, len, ans, ind + 1);	//if did not accept that alphabet
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		cin >> ch[i];
	}

	sort(ch, ch + c);
	string n;

	bt(0, 0, 0, n, 0);

	return 0;
}
