#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<int,int>> u;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		u.push_back({ a,b });
	}
	long long ans = 0;
	for (int i = n - 2; i >= 0; --i)
		ans += 1LL*u[i].first * u[i].second * u[n - 1].second;
	cout << ans;
}