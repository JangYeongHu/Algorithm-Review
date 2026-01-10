#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		ll n,a,b; cin >> n >> a >> b;
		ll nn = 1LL<<n;
		if(a<b) swap(a,b);
		int ans = 1;
		while(nn) {
			ll m = nn/2;
			if(m==a) {
				cout << ans << "\n";
				break;
			} else if(m<a) {a-=m;}
			nn/=2;
			ans++;
		}
	}
	return 0;
}