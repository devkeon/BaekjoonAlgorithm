#include <iostream>
#define MAX 2147483646

using namespace std;

int n, k;
int p[10000];
int p_set[10001];
int pp_set[10001];
int ans[1] = { MAX };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p_set[p[i]]++;
	}
	int right = 0, left = 0;
	int pc = k, ppc = 0;	//color num of p & p'

	pp_set[p[left]]++; 
	ppc++;

	p_set[p[left]]--;

	if (p_set[p[left]] == 0)
		pc--;

	while (right < n) {
		if (ppc == k) {	//left only here
			if(ans[0] > right - left + 1 && pc == k)	//double rainbow
				ans[0] = right - left + 1;

			pp_set[p[left]]--;
			p_set[p[left]]++;
			if (pp_set[p[left]] == 0)	//if p' color become 0
				ppc--;
        
			if (p_set[p[left]] == 1)  //if p color become 1, that means one kind of color increase
				pc++;
        
			left++;
		}
		else {
			right++;

			p_set[p[right]]--;

			if (p_set[p[right]] == 0)
				pc--;

			pp_set[p[right]]++;

			if (pp_set[p[right]] == 1)
				ppc++;
		}
	}

	if (ans[0] != MAX)
		cout << ans[0];
	else
		cout << 0;

	return 0;
}
