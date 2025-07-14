#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> yun;
stack<pair<int, int>> st;
vector<int> gan;
vector<int> nu;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, h; cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		yun.push_back({ a,b });
	}

	sort(yun.begin(), yun.end(), cmp);

	for (int i = 0; i < yun.size(); i++) {
		if (i == 0) { st.push(yun[i]); continue; }
		if (st.top().second >= yun[i].first) {
			auto t = st.top();
			st.pop();
			st.push({ min(t.first,yun[i].first),max(t.second,yun[i].second) });
		}
		else {
			st.push(yun[i]);
		}
	}
	if (st.empty()) {
		gan.push_back(h);
	}
	else {
		auto t = st.top();
		st.pop();
		gan.push_back(h - t.second);
		while (!st.empty()) {
			gan.push_back(t.first - st.top().second - 1);
			t = st.top();
			st.pop();
		}
		gan.push_back(t.first-1);
	}

	sort(gan.begin(), gan.end());

	nu.push_back(gan[0]);

	for (int i = 1; i < gan.size(); i++)
		nu.push_back(nu[i - 1] + gan[i]);
	
	int q; cin >> q;
	while (q--) {
		int t; cin >> t;
		int idx = lower_bound(gan.begin(), gan.end(), t) - gan.begin();
		int cnt = nu.size() - (idx == 0 ? 0 : idx);
		int hap = nu.back() - (idx == 0 ? 0 : nu[idx - 1]);
		cout << hap - (t - 1) - (t - 1) * (cnt-1) << "\n";
	}

	return 0;
}