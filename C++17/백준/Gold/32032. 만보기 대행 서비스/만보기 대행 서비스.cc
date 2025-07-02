#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;
ll pos[1'000'000];

ll n, d;
ll get() {
	if (pos[0] > 0) return pos[n - 1] * 2 + d;
	if (pos[n - 1] < 0) return pos[0] * -2 + d;
	ll dis = pos[n - 1] - pos[0];
	ll ans = dis * 2 + d + min(min(pos[n - 1] * 2, d), pos[0] * -2);

	ll t1 = 4 * dis + ((2 * dis < d) ? d - 2 * dis : 0);

	return min(ans,t1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	sort(pos, pos + n);

	cout << get();

	return 0;
}