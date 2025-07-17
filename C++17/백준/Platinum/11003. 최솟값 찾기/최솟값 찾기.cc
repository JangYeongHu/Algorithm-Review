#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, l; cin >> n >> l;
	deque<pair<int,int>> deq;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		while (!deq.empty() && deq.back().second >= t) deq.pop_back();
		deq.push_back({i,t});
		if (deq.front().first <= (i - l)) deq.pop_front();
		cout << deq.front().second<<" ";
	}

	return 0;
}