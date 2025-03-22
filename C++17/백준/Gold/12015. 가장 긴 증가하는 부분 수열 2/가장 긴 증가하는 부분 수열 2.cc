#include <bits/stdc++.h>
using namespace std;
int d[1'000'010];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n,ans = 0;
	cin >> n;
	for (int i = 0; i < n+2; i++)
		d[i] = 1 << 28;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		int start = 1, end = n,mid;
		while (start < end) {
			mid = (start + end) / 2;
			if (d[mid] >= t) {
				end = mid;
			}
			else {
				start = mid+1;
			}
		}
		d[start] = min(t,d[start]);
		ans = max(ans, start);
	}
	cout << ans;
}