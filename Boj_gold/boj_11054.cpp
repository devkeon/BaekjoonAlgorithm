#include <iostream>
#include <algorithm>

using namespace std;

int dp_inc[1000];  //greater
int dp_dec[1000];
int seq[1000];
int n, ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> seq[i];

	for (int i = 0; i < n; i++) {  //greater 
		int cnt = 1;
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j])
				cnt = max(cnt, dp_inc[j] + 1);
		}
		dp_inc[i] = cnt;
	}
	for (int i = n - 1; i >= 0; i--) {  //greater 
		int cnt = 1;
		for (int j = i; j < n; j++) {
			if (seq[i] > seq[j])
				cnt = max(cnt, dp_dec[j] + 1);
		}
		dp_dec[i] = cnt;
	}

	for (int i = 0; i < n; i++) {
		ans = max(ans, dp_inc[i] + dp_dec[i] - 1);
	}

	cout << ans;

	return 0;
}
