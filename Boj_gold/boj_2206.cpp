#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int n, m;  //row, column
int move_row[4] = { -1, 0, 1, 0 };
int move_col[4] = { 0, 1, 0, -1 };
char map[1000][1000];
int ans[2][1000][1000] = { {{1}} };  //erase path in two way(break the wall or keep going)


int bfs(int row, int col, int cnt) {  //BFS
	queue<tuple<int, int, bool>> q;

	q.push(make_tuple(row, col, false));  //false = 0, true = 1

	while (!q.empty()) {
		int ROW = get<0>(q.front());
		int COL = get<1>(q.front());
		bool visit = get<2>(q.front());

		q.pop();

		if (ROW == n - 1 && COL == m - 1) {
			if (visit == true)
				return ans[1][n - 1][m - 1];
			else
				return ans[0][n - 1][m - 1];
		}

		for (int i = 0; i < 4; i++) {
			int row = ROW + move_row[i];
			int col = COL + move_col[i];

			if ((row >= 0 && col < m) && (row < n && col >= 0)) {

				if (map[row][col] == '0' && ans[visit][row][col] == 0) {  //if not yet visit & not a wall
					q.push(make_tuple(row, col, visit));
					ans[visit][row][col] = ans[visit][ROW][COL] + 1;
				}
				else if (map[row][col] == '1' && visit == false) {  //if not yet broke wall & there is a wall
					q.push(make_tuple(row, col, true));
					ans[true][row][col] = ans[visit][ROW][COL] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}

	cout << bfs(0, 0, 1);

	return 0;
}
