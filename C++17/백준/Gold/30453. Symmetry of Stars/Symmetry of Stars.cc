#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

map<pair<int,int>,int> vis;
vector <pair<int, int>> stars;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		stars.push_back({ a,b });
		vis[{a+a,b+b}]++;
	}
	int mx = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			auto p = stars[i],c = stars[j];
			pair<int, int> a = { p.x + c.x, p.y + c.y };
			vis[a]+=2;
		}
	}

	for (auto iter : vis)
		mx = max(iter.second, mx);

	cout << mx;

	return 0;
}