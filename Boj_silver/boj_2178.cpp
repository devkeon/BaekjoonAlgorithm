#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int n, m;
char maze[100][100];  //graph, show available path
int path[100][100];  //least number of cases

void bfs(int x, int y) {  //bfs to find least num
	queue<pair<int,int>> q;
	pair<int, int> p = make_pair(x, y);
	q.push(p);
	maze[y][x] = '0';  //erase used path so it could calculate least path
	path[y][x] = 1;

	while (!q.empty()) {
		int tempx = q.front().first;
		int tempy = q.front().second;
		q.pop();
		if (tempx - 1 >= 0) {
			if (maze[tempy][tempx - 1] == '1') {
				path[tempy][tempx - 1] = path[tempy][tempx] + 1;  //add 1 to go next path
				maze[tempy][tempx - 1] = '0';
				p = make_pair(tempx - 1, tempy);
				q.push(p);
			}
		}
		if (tempx + 1 < m) {
			if (maze[tempy][tempx + 1] == '1') {
				path[tempy][tempx + 1] = path[tempy][tempx] + 1;
				maze[tempy][tempx + 1] = '0';
				p = make_pair(tempx + 1, tempy);
				q.push(p);
			}
		}
		if (tempy - 1 >= 0) {
			if (maze[tempy - 1][tempx] == '1') {
				path[tempy - 1][tempx] = path[tempy][tempx] + 1;
				maze[tempy - 1][tempx] = '0';
				p = make_pair(tempx, tempy - 1);
				q.push(p);
			}
		}
		if (tempy + 1 < n) {
			if (maze[tempy + 1][tempx] == '1') {
				path[tempy + 1][tempx] = path[tempy][tempx] + 1;
				maze[tempy + 1][tempx] = '0';
				p = make_pair(tempx, tempy + 1);
				q.push(p);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int y = 0; y < n; y++) {  //input have no space so use char to seperate each other
		for (int x = 0; x < m; x++) {
			cin >> maze[y][x];
		}
	}
	bfs(0, 0);

	cout << path[n - 1][m - 1];

	return 0;
}
