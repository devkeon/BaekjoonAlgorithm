#include <iostream>

using namespace std;

char ans[2187][2187] = { 0, };

void base(int n, int i, int j) {
	if (n > 1) {
		int tri = n / 3;  //variable for operation

		for (int ti = i; ti < n + i; ti++) {
			for (int tj = j; tj < n + j; tj++) {
				if ((tj < tri + j || tj > tri * 2 - 1 + j) || (ti < tri + i || ti > tri * 2 - 1 + i)) {  //except area that is n / 3 * n / 3
					if (ans[ti][tj] == 0) {  //if there is notihng written
						ans[ti][tj] = '*';
					}
				}
				else
					ans[ti][tj] = ' ';
			}
		}
		for (int h = 0; h < 3; h++) {
			for (int k = 0; k < 3; k++) {
				base(tri, i + h * tri, j + k * tri);  //recursion, call lower square and finish writting *
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	base(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << ans[i][j];
		cout << "\n";
	}
	return 0;
}
