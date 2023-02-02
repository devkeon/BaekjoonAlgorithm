#include <iostream>

using namespace std;

int n;
int dp[100][10] = { {0,1,1,1,1,1,1,1,1,1} };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0 && j + 1 <= 9)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
			else if (j - 1 < 0)  //if j == 0
				dp[i][j] = dp[i - 1][j + 1] % 1000000000;
			else  //if j == 9
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[n - 1][i]) % 1000000000;
	}
	cout << ans;

	return 0;
}
