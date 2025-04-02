#include <bits/stdc++.h>
using namespace std;
int cnt[32001];
vector<int> sons[32001];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	priority_queue<int> pq;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cnt[b]++;
		sons[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] == 0) pq.push(-i);

	while (!pq.empty()) {
		int num = -pq.top();
		pq.pop();
		cout << num << "\n";
		for (auto s : sons[num]) {
			cnt[s]--;
			if (cnt[s] == 0) pq.push(-s);
		}
	}
}