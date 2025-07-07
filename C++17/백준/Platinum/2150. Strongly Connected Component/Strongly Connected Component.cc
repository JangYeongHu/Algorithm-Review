#include <bits/stdc++.h>
using namespace std;

int id[10001];
int low_link[10001];
bool on_stack[10001];
int cnt = 0;
vector<int> edges[10001];
stack<int> st;
vector<vector<int>> ans;

void dfs(int now) {
	on_stack[now] = 1;
	st.push(now);
	id[now] = ++cnt;
	low_link[now] = cnt;

	for (auto nxt : edges[now]) {
		if (!id[nxt]) {
			dfs(nxt);
			low_link[now] = min(low_link[now], low_link[nxt]);
		}
		else if (on_stack[nxt]) {
			low_link[now] = min(low_link[now], id[nxt]);
		}
	}

	if (low_link[now] == id[now]) {
		vector<int> scc;
		while (!st.empty()) {
			int top = st.top(); st.pop();
			scc.push_back(top);
			on_stack[top] = 0;
			if (now == top) break;
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int v, e; cin >> v >> e;
	while (e--) {
		int a, b; cin >> a >> b;
		edges[a].push_back(b);
	}

	for (int i = 1; i <= v; i++) {
		if (!id[i]) dfs(i);
	}
	cout << ans.size() << "\n";

	sort(ans.begin(), ans.end());
	for (auto v : ans) {
		for (int i : v) cout << i << " ";
		cout << "-1\n";
	}
}
