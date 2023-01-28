#include <iostream>
#include <queue>

using namespace std;

char pic[2][100][100];  //[0] == normal, [1] == amblyopia
int mx[] = { -1, 0, 1, 0 };
int my[] = { 0, 1, 0, -1 };
int n;
queue<pair<int, int>> q;

void bfs(int x, int y, char color, int norm) {  //use bfs to erase same colors adjacent to each other
	q.push(make_pair(x, y));
	pic[norm][x][y] = NULL;
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nextx = nx + mx[k];
			int nexty = ny + my[k];
			if ((nextx >= 0 && nexty < n) && (nextx < n && nexty >= 0)) {
				if (pic[norm][nextx][nexty] == color) {
					q.push(make_pair(nextx, nexty));
					pic[norm][nextx][nexty] = NULL;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int normal = 0, amblyopia = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			pic[0][i][j] = tmp;
			if (tmp == 'R') {
				pic[1][i][j] = 'G';
			}
			else {
				pic[1][i][j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pic[0][i][j] != NULL) {  //if not yet erased
				bfs(i, j, pic[0][i][j], 0);
				normal += 1;
			}
			if (pic[1][i][j] != NULL) {
				bfs(i, j, pic[1][i][j], 1);
				amblyopia += 1;
			}
		}
	}
	cout << normal << " " << amblyopia;

	return 0;
}
