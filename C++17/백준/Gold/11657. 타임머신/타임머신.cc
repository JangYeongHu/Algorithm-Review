#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1<<30
using namespace std;
long long dis[501];
vector<pair<int,int>> edge[501];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[1] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[j] == INF) continue;
			for (auto iter = edge[j].begin(); iter != edge[j].end(); iter++) {
				int b = iter->first, c = iter->second;
				if (dis[b] > dis[j] + c) {
					if (i == n-1) { cout << "-1"; return 0; }
					else dis[b] = dis[j] + c; }
			}
		}
	}
	for (int i = 2; i <= n; i++)
		if (dis[i] == INF) cout << -1 << "\n";
		else cout << dis[i] << "\n";
	return 0;
}