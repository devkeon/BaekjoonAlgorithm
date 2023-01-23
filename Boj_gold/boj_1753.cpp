#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
#define max 20001

using namespace std;

vector<int> ans;
vector<pair<int, int>> path[max];
int v, e, start;

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;  //use priority queue to calculate shortest dist first

	pq.push(make_pair(0, start));
	ans[start] = 0;

	while (!pq.empty()) {
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < path[node].size(); i++) {
			int next_dist = path[node][i].first;
			int next_node = path[node][i].second;

			if (ans[next_node] > next_dist + weight) {  //if renew dist
				ans[next_node] = next_dist + weight;
				pq.push(make_pair(next_dist + weight, next_node));  //push node to visit & write shrotest dist to that node
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e >> start;

	ans.resize(v + 1, INF);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		path[u].push_back(make_pair(w,v));  //path[u].first == weight, path[u].second == dest vertex
	}

	dijkstra(start);

	for (int n = 1; n <= v; n++) {
		if (ans[n] == INF) {
			cout << "INF\n";
		}
		else
			cout << ans[n] << "\n";
	}

	return 0;
}
