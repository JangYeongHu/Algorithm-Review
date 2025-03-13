#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> nodes[100001];
bool vis[100001];

pair<int,int> dfs(int x) {
	vis[x] = 1;
	int mx = 0,ind = 0;
	for (auto t : nodes[x]) {
		if (vis[t.first]) continue;
		auto a = dfs(t.first);
		if (a.second+t.second > mx) { mx = a.second + t.second; ind = a.first; }
	}
	vis[x] = 0;
	return { ind ? ind : x,mx };
}

int main() {
	int v;
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int num;
		cin >> num;
		int e, d;
		while (1) {
			cin >> e;
			if (e == -1) break;
			cin >> d;
			nodes[num].push_back({ e,d });
		}
	}
	int x = dfs(1).first;
	cout << dfs(x).second;
}