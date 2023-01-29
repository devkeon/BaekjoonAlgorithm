#include <iostream>
#include <algorithm>

using namespace std;

int n;
int bamboo[500][500];
int dp[500][500];
int ans[1];
int move_r[] = { -1, 0, 1, 0 };
int move_c[] = { 0, 1, 0, -1 };

int dfs(int x, int y) {
	if (dp[x][y] != NULL)
		return dp[x][y];

	dp[x][y] = 1;

	for (int k = 0; k < 4; k++) {
		int nx = x + move_r[k];
		int ny = y + move_c[k];
		if ((nx >= 0 && ny < n) && (nx < n && ny >= 0)) {  //in the range
			if (bamboo[nx][ny] > bamboo[x][y]) {  //next bamboo is bigger
				dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);  //recursion
			}
		}
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bamboo[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[0] = max(dfs(i, j), ans[0]);

		}
	}

	cout << ans[0];

	return 0;
}
