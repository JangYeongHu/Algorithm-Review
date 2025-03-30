#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int backpack[300'000];
pair<int,int> bosuk[300'000];
bool vis[300'001];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> bosuk[i].first >> bosuk[i].second;

	for (int i = 0; i < k; i++)
		cin >> backpack[i];
	sort(backpack, backpack + k);
	sort(bosuk, bosuk + n);
	long long idx = 0, ans = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && backpack[i] >= bosuk[idx].first) {
			pq.push(bosuk[idx].second);
			idx++;
		}
		if (pq.empty()) continue;
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
}