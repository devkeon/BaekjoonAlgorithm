#include <iostream>
#include <queue>

using namespace std;

int tomato[1000][1000] = { 0, };
int n, m;

int check(int tomato[][1000]) {  //check if there is 0 in tomato[][]
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (tomato[y][x] == 0) {
				return -1;  //if tomato[][] = 0  remain, that case could not make it
			}
		}
	}
	return 1;
}

int bfs(queue<pair<int, int>> q, int count) {
	int temp[1] = { 0 };  //count it next simultaneous number of nodes
	int ans = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (count == 0) {  //if simultaneous operation is over, day + 1 and change it to next operation
			count = temp[0];
			temp[0] = 0;
			ans++;
		}
		count --;

		if (x + 1 < m) {
			if (tomato[y][x + 1] == 0) {
				tomato[y][x + 1] = 1;
				q.push(make_pair(x + 1, y));
				temp[0]++;
			}
		}
		if (x - 1 >= 0) {
			if (tomato[y][x - 1] == 0) {
				tomato[y][x - 1] = 1;
				q.push(make_pair(x - 1, y));
				temp[0]++;
			}
		}
		if (y - 1 >= 0) {
			if (tomato[y - 1][x] == 0) {
				tomato[y - 1][x] = 1;
				q.push(make_pair(x, y - 1));
				temp[0]++;
			}
		}
		if (y + 1 < n) {
			if (tomato[y + 1][x] == 0) {
				tomato[y + 1][x] = 1;
				q.push(make_pair(x, y + 1));
				temp[0]++;
			}
		}
	}
	return ans;
}

int main()
{
	int count = 0;  //save how many nodes should consider in same time
	queue<pair<int, int>> q;

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			tomato[i][j] = tmp;
			if (tmp == 1) {  //if tomato[y][x] == 1, count it for first operation
				count++;
				q.push(make_pair(j, i));
			}
		}
	}

	int a = bfs(q, count);
	int t = check(tomato);
	
	if (t == -1)
		cout << "-1";
	else
		cout << a;
	return 0;
}
