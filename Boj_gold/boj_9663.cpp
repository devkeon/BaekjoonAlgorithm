#include <iostream>

using namespace std;

int queen[15] = { -1 };
int n;

int check(int x, int i) {
	for (int h = 0; h < x; h++) {  //check other queens that have same y coordinate
		if (queen[h] == i)
			return 1;
	}
	for (int j = 1; j <= x; j++) {  //check other queens that is on the diagonal range
		if (queen[x - j] == queen[x] - j) {
			return 1;
		}
	}
	for (int m = 1; m <= x; m++) {
		if (queen[x - m] == queen[x] + m)
			return 1;
	}
	return 2;
}

void N_queen(int x, int count[1]) {
	for (int i = 0; i < n; i++) {
		queen[x] = i;
		int judge = check(x, i);  //if it could put queen on that area return 2
		if (judge == 2) {
			if (x == n - 1) {  //if all queens put
				count[0] ++;
			}
			else {
				N_queen(x + 1, count);  //recursion
			}
		}
		queen[x] = -1;
	}
}

int main() {
	cin >> n;
	int count[1] = { 0 };

	N_queen(0, count);

	cout << count[0];

	return 0;
}
