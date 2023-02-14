#include <iostream>

using namespace std;

int n, m;
int paper[500][500], ans[1] = { 0 };
int mr[] = { -1,0,1,0 }, mc[] = { 0, 1, 0, -1 };
bool visit[500][500];

void answer(int tmp) {
	if (tmp > ans[0])
		ans[0] = tmp;
}

void tetromino(int row, int col, int depth, int summ) {
	visit[row][col] = true;
	if (depth == 4) {
		if (summ > ans[0])
			ans[0] = summ;
	}
	else {
		for (int x = 0; x < 4; x++) {
			int nr = row + mr[x];
			int nc = col + mc[x];
			if ((nr < n && nr >= 0) && (nc < m && nc >= 0)) {
				if(visit[nr][nc] != true)
					tetromino(nr, nc, depth + 1, summ + paper[nr][nc]);
			}
		}
	}
	visit[row][col] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			tetromino(r, c, 1, paper[r][c]);
			if (c + 2 < m && r + 1 < n) {	//ㅜ
				answer(paper[r][c] + paper[r][c + 1] + paper[r + 1][c + 1] + paper[r][c + 2]);
			}
			if (c - 1 >= 0 && r + 2 < n) {	//ㅓ
				answer(paper[r][c] + paper[r + 1][c] + paper[r + 1][c - 1] + paper[r + 2][c]);
			}
			if (c + 1 < m && r + 2 < n)	//ㅏ
				answer(paper[r][c] + paper[r + 1][c] + paper[r + 1][c + 1] + paper[r + 2][c]);
			if (c + 2 < m && r - 1 >= 0)	//ㅗ
				answer(paper[r][c] + paper[r][c + 1] + paper[r - 1][c + 1] + paper[r][c + 2]);
		}
	}
	cout << ans[0];

	return 0;
}
