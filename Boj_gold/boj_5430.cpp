#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		deque<string> dq;
		string arr, tmp = "";
		int n;
		string p;
		int sig = 0;  //0 = front 1 = back

		cin >> p >> n >> arr;

		for (int k = 0; k < arr.length(); k++) {
			if (isdigit(arr[k]) != 0)	//use isdigit to seperate integer from array input
				tmp += arr[k];
			else {
				if (!tmp.empty()) {
					dq.push_back(tmp);
					tmp = "";
				}
			}
		}

		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {	//reverse front/back signal
				if (sig == 0)
					sig = 1;
				else
					sig = 0;
			}
			else {
				if (dq.empty()) {	//if array is empty but try to discard
					cout << "error\n";
					sig = 3;	//change signal to show already print error
					break;
				}
				else if (sig == 0) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}

		if(sig != 3) {
			cout << "[";
			while (!dq.empty()) {
				if (sig == 0) {
					cout << dq.front();
					dq.pop_front();
				}
				else {
					cout << dq.back();
					dq.pop_back();
				}
				if (!dq.empty())
					cout << ",";
			}
			cout << "]\n";
		}
	}
	return 0;
}
