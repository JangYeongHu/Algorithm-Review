#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int time = 0,ans=0;
	while (n--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int t = time % (c + d);
		if (t < c) {
			time += a;
			ans += a;
		}
		else if(c + d - t + a < b){
			ans += c + d - t + a;
			time += c + d - t + a;
		} else {
			time += b;
			ans += b;
		}
	}
	cout << ans;
}