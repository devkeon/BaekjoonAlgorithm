#include <iostream>

using namespace std;
int R, C, ans[1] = { 0 };
int board[20][20];
bool alphabet[26] = { false, };
int x_move[4] = { -1, 0, 1, 0 };
int y_move[4] = { 0, 1, 0, -1 };

void move(int x, int y, int cnt) {  //dfs
	for (int i = 0; i < 4; i++) {
		int tmpx = x + x_move[i];
		int tmpy = y + y_move[i];

		if ((tmpx >= 0 && tmpy < R) && (tmpx < C && tmpy >= 0)) {  //if up, down, left, right is in the range
			int next = board[tmpy][tmpx];
			if (next != -1 && alphabet[next] != true) {
				board[tmpy][tmpx] = -1;
				alphabet[next] = true;
				move(tmpx, tmpy, cnt + 1);
				alphabet[next] = false;
				board[tmpy][tmpx] = next;
			}
			else {
				if (ans[0] < cnt) {  //refresh max element
					ans[0] = cnt;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {  //y
		for (int j = 0; j < C; j++) {  //x
			char tmp;
			cin >> tmp;
			board[i][j] = tmp - 'A';  //index of alphabet
		}
	}
	alphabet[board[0][0]] = true;
	board[0][0] = -1;

	move(0, 0, 1);

	cout << ans[0];

	return 0;
}
