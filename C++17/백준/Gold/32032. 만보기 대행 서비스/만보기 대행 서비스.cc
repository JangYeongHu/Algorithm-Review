#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll = long long;
ll pos[1'000'000];

ll n, d;
ll get() {
	if (pos[0] > 0) return pos[n - 1] * 2 + d;
	if (pos[n - 1] < 0) return pos[0] * -2 + d;
	int z_p = (upper_bound(pos, pos + n, 0) - pos);

	ll ans = 0;
	ll dis = pos[n - 1] - pos[0];
	ans += dis * 2;
	ans += min(min(pos[n - 1] * 2, d), pos[0] * -2);
	ans += d;

	ll t1 = 4 * dis;

	t1 += (2 * dis < d) ? d - 2 * dis : 0;

	return min(ans,t1);
}

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	sort(pos, pos + n);

	cout << get();

	return 0;
}