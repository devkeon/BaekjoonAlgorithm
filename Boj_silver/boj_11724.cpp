#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
int graph[1001][1001] = { 0, };
bool visit[1001];

void dfs(int start) {
	visit[start] = true;
	for (int i = 1; i <= n; i++) {
		if (graph[start][i] == 1 && visit[i] == false) {
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int inp, outp;
		cin >> inp >> outp;
		graph[inp][outp] = 1;
		graph[outp][inp] = 1;
	}

	for (int j = 1; j <= n; j++) {
		if (visit[j] == false) {
			dfs(j);
			ans++;
		}
	}

	cout << ans;

	return 0;
}
