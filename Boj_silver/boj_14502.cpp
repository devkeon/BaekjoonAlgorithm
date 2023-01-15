#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int lab[8][8];
int ans[1] = { -1 };
int n, m;  // n = vertical m = horizontal

queue<pair<int, int>> virus;
vector<pair<int, int>> empt;

int infection(queue<pair<int, int>> &virus, int temp[][8]) {  //make it infection and calculate how many labs survive

	while (!virus.empty()) {
		int tx = virus.front().first;
		int ty = virus.front().second;
		virus.pop();
		temp[ty][tx] = 2;
		if (tx - 1 >= 0) {
			if (temp[ty][tx - 1] == 0) {
				virus.push(make_pair(tx - 1, ty));
			}
		}
		if (tx + 1 < m) {
			if (temp[ty][tx + 1] == 0) {
				virus.push(make_pair(tx + 1, ty));
			}
		}
		if (ty - 1 >= 0) {
			if (temp[ty - 1][tx] == 0) {
				virus.push(make_pair(tx, ty - 1));
			}
		}
		if (ty + 1 < n) {
			if (temp[ty + 1][tx] == 0) {
				virus.push(make_pair(tx, ty + 1));
			}
		}
	}
	int count = 0;
	for (int y = 0; y < n; y++) {  //operate survived lab
		for (int x = 0; x < m; x++) {
			if (temp[y][x] == 0)
				count++;
		}
	}
	return count;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	vector<pair<int, int>> save;

	for(int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			lab[i][j] = tmp;
			if (tmp == 2) {  //if there is virus
				virus.push(make_pair(j, i));
				save.push_back(make_pair(j, i));
			}
			else if (tmp == 0)  //if there is empty
				empt.push_back(make_pair(j, i));
		}
	}

	for (int i = 0; i < empt.size() - 2; i++) {
		for (int j = i + 1; j < empt.size() - 1; j++) {
			for (int k = j + 1; k < empt.size(); k++) {
				int temp[8][8];
				copy(&lab[0][0], &lab[0][0] + 8 * 8, &temp[0][0]);  //copy lab to save first state and reuse it
				temp[empt[i].second][empt[i].first] = 1;  //pick three place to build wall
				temp[empt[j].second][empt[j].first] = 1;
				temp[empt[k].second][empt[k].first] = 1;
				int maybe = infection(virus, temp);
				
				if (maybe > ans[0]) {
					ans[0] = maybe;
				}

				for (int t = 0; t < save.size(); t++) {
					virus.push(save[t]);
				}
			}
		}
	}
	cout << ans[0];

	return 0;
}
