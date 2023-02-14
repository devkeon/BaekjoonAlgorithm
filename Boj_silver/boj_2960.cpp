#include <iostream>

using namespace std;

int n, k, cnt = 0, e_flag = 0, ans;
bool visit[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		if (visit[i] == false) {
			for (int j = 1; j * i <= n; j++) {
				if (visit[j * i] != true) {
					visit[j * i] = true;
					cnt++;
					if (cnt == k) {
						e_flag = 1;
						ans = j * i;
						break;
					}
				}
			}
		}
		if (e_flag == 1)
			break;
	}
	cout << ans << "\n";

	return 0;
}
