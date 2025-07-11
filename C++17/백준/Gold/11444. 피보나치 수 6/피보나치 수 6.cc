#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define Z 1000000007

void gob(ll a[][2], ll b[][2]) {
	ll t[2][2];
	t[0][0] = (a[0][0] * b[0][0] % Z + a[0][1] * b[1][0] % Z) % Z;
	t[0][1] = (a[0][0] * b[0][1] % Z + a[0][1] * b[1][1] % Z) % Z;
	t[1][0] = (a[1][0] * b[0][0] % Z + a[1][1] * b[1][0] % Z) % Z;
	t[1][1] = (a[1][0] * b[0][1] % Z + a[1][1] * b[1][1] % Z) % Z;
	a[0][0] = t[0][0];
	a[1][0] = t[1][0];
	a[0][1] = t[0][1];
	a[1][1] = t[1][1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n; cin >> n;
	ll c[][2] = { {1,1},{1,0} };
	ll a[][2] = { {1,1},{1,0} };
	while (n) {
		if (n % 2)
			gob(a, c);
		gob(c, c);
		n /= 2;
	}
	cout << a[1][1];
	return 0;
}