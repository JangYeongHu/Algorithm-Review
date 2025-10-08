#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n, m; cin >> n >> m;
	ll t, s; cin >> t >> s;
	ll sleep = n / 8;
	if (n % 8 == 0) sleep--;
	ll t1 = n + sleep*s;
	sleep = m / 8;
	if (m % 8 == 0) sleep--;
	ll t2 = m + sleep*s + sleep * t * 2 + t;
	if (t1 < t2) cout << "Zip\n" << t1;
	else cout << "Dok\n" << t2;
}