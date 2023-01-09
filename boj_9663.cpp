#include <iostream>
#include <vector>

using namespace std;

int combination(int n, int r) {  //���� ���
	if (r == 0)
		return 1;
	else if (n == r)
		return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	vector<int> ans;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		ans.push_back(combination(m, n));  //���� ��� �� �ٷ� ����
	}
	for (int j = 0; j < t; j++)  //���
		cout << ans[j] << "\n";

	return 0;
}