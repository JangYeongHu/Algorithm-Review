#include <bits/stdc++.h>
using namespace std;
long long d[200'001];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i+1];
	int q; cin >> q;
	while (q--) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int c, x; cin >> c >> x;
			long long t = c, xt = x;
			while (xt>0) {
				long long so = min(d[t], xt);
				d[t] += so;
				xt -= so;
				t--;
				if (t<=0)break;
			}
			t = c + 1, xt = x;
			while (xt>0) {
				long long so = min(d[t], xt);
				d[t] += so;
				xt -= so;
				t++;
				if (t > n)break;
			}
		}
		else {
			int c; cin >> c;
			cout << d[c] << "\n";
		}
	}

	return 0;
}