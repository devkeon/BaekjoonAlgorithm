#include <iostream>
#include <vector>

using namespace std;

int dp[31][31] = { {-1} };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> ans;
	
	for (int l = 1; l <= 30; l++) {  //�� �� �� ���
		dp[l][0] = 1;
		dp[l][l] = 1;
	}

	for (int k = 2; k <= 30; k++) {  //30������ ���� �� ���
		for (int h = 1; h <= k; h++) {
			dp[k][h] = dp[k - 1][h - 1] + dp[k - 1][h];
		}
	}

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		ans.push_back(dp[m][n]);
	}
	for (int j = 0; j < t; j++)  //���
		cout << ans[j] << "\n";

	return 0;
}