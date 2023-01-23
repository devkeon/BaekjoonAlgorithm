#include <iostream>
#include <vector>
#include <algorithm>
#define MAX(A, B) ((A>B)?(A):(B))  //return bigger element

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<pair<int, int>> w_v;
	int n, k;
	int ans[1] = { 0 };
	cin >> n >> k;
	vector<vector<int>> dp(n, vector<int>(k + 1));
	
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		w_v.push_back(make_pair(w, v));
	}

	for (int m = 0; m <= k; m++) {  //first line of dp table
		if (m - w_v[0].first >= 0)
			dp[0][m] = w_v[0].second;
		else
			dp[0][m] = 0;
		if (ans[0] < dp[0][m])
			ans[0] = dp[0][m];
	}

	for (int i = 1; i < n; i++) {
		for (int m = 0; m <= k; m++) {
			int weight = w_v[i].first;
			int value = w_v[i].second;
			if (weight <= m) {  //weight is smaller than max weight
				dp[i][m] = MAX(dp[i - 1][m], dp[i - 1][m - weight] + value);  //choose bigger one 
			}
			else {
				dp[i][m] = dp[i - 1][m];
			}
			if (ans[0] < dp[i][m])
				ans[0] = dp[i][m];  //max element
		}
	}

	cout << ans[0];

	return 0;
}
