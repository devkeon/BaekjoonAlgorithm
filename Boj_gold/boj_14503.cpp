#include <iostream>

using namespace std;
int n, m, r, c, d;
int ans[1];
int map[50][50];  //0 = blank, 1 = wall, -1 = cleaned
int mr[] = { -1, 0, 1, 0 };
int mc[] = { 0, 1, 0, -1 };

int ahead(int direction) {
	if (direction - 1 < 0)
		return 3;
	else
		return direction - 1;
}

int backward(int dir) {
	if (dir - 2 == -1)
		return 3;
	else if (dir - 2 == -2)
		return 2;
	else
		return dir - 2;

}

void dfs(int r, int c, int d, int cnt, int turn) {
	int head = d;
	int left = ahead(d);
	int back = backward(d);
	map[r][c] = -1;
	int nr = r + mr[left];
	int nc = c + mc[left];
	int br = r + mr[back];
	int bc = c + mc[back];

	if (map[nr][nc] == 0) {
		dfs(nr, nc, left, cnt + 1, 0);
	}
	else if (map[nr][nc] != 0 && turn < 4) {
		dfs(r, c, left, cnt, turn + 1);
	}
	else if (turn == 4 && map[br][bc] != 1) {
		dfs(br, bc, d, cnt, 0);
	}
	else if (turn == 4 && map[br][bc] == 1) {
		ans[0] = cnt;
		return;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	if(map[r][c] == 0)
		dfs(r, c, d, 1, 0);
	else
		dfs(r, c, d, 0, 0);

	cout << ans[0];

	return 0;
}
