#include <iostream>
#define MAX 2147483646

using namespace std;

int n, k;
int dp[10001];
int coin[100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= k; i++)  //array reset
		dp[i] = MAX;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - coin[j] == 0) {  //if dp[i] can make with one coin
				dp[i] = 1;
			}
			else if (i - coin[j] > 0) {
				if (dp[i - coin[j]] + 1 < dp[i]) {  //if current dp[i] is bigger than dp[i - coin[j]]
					dp[i] = dp[i - coin[j]] + 1;
				}
			}
		}
	}
	if (dp[k] != MAX)
		cout << dp[k];
	else
		cout << -1;

	return 0;
}
