#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

char map[25][25];
int n;

int apt(int x, int y) {  //bfs
	queue<pair<int, int>> q;
	int apt_num = 0;
	q.push(make_pair(x, y));
	map[y][x] = '0';  //erase apt location then safe from overlap
	
	while (!q.empty()) {
		int tempx = q.front().first;
		int tempy = q.front().second;
		q.pop();
		apt_num++;  //if q pop, apt_num + 1

		if (tempx - 1 >= 0) {
			if (map[tempy][tempx - 1] == '1') {
				q.push(make_pair(tempx - 1, tempy));
				map[tempy][tempx - 1] = '0';
			}
		}
		if (tempx + 1 < n) {
			if (map[tempy][tempx + 1] == '1') {
				q.push(make_pair(tempx + 1, tempy));
				map[tempy][tempx + 1] = '0';
			}
		}
		if (tempy - 1 >= 0) {
			if (map[tempy - 1][tempx] == '1') {
				q.push(make_pair(tempx, tempy - 1));
				map[tempy - 1][tempx] = '0';
			}
		}
		if (tempy + 1 < n) {
			if (map[tempy + 1][tempx] == '1') {
				q.push(make_pair(tempx, tempy + 1));
				map[tempy + 1][tempx] = '0';
			}
		}
	}
	return apt_num;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			map[i][j] = tmp;
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x] == '1') {  //if found one apartment, run apt function
				ans.push_back(apt(x, y));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int k = 0; k < ans.size(); k++) {
		cout << ans[k] << "\n";
	}

	return 0;
}
