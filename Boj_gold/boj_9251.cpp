#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001];
string fs, ss;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> fs >> ss;

	for (int i = 0; i < fs.length(); i++) {
		dp[i][0] = 0;
	}
	for (int i = 0; i < ss.length(); i++) {
		dp[0][i] = 0;
	}

	for (int i = 0; i < fs.length(); i++) {
		for (int j = 0; j < ss.length(); j++) {
			if (fs[i] == ss[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	cout << dp[fs.length()][ss.length()];

	return 0;
}
