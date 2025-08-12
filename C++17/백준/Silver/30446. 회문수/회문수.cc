#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n; cin >> n;
	int hf = 1,ans = 0; 
	ll e, o;
	do {
		string a = to_string(hf);
		string b = a;
		reverse(b.begin(), b.end());
		e = stoll(a + b);
		o = stoll(a + b.substr(1,b.size()));
		if (e <= n) ans++;
		if (o <= n) ans++;
		hf++;
	} while (e <= n || o <= n);

	cout << ans;
	
	return 0;
}