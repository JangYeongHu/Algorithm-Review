#include <bits/stdc++.h>
using namespace std;
#define SZ 2'000'000
int tree[4 * SZ+9];

void update(int n, int s, int e, int k,int x) {
	if (s > k || e < k) return;
	if (s == e) { tree[n]+=x; return; }
	int m = (s + e) / 2;
	update(n * 2, s, m,k,x);
	update(n * 2+1, m+1, e, k,x);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int get(int n, int s, int e, int x) {
	if (s == e) return s;
	int m = (s + e) / 2;
	if (tree[n * 2] >= x) return get(n * 2, s, m, x);
	else return get(n * 2 + 1, m+1, e, x - tree[n * 2]);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n;
	while (n--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			update(1, 1, SZ, x,1);
		}
		else {
			int ans = get(1, 1, SZ, x);
			cout << ans << "\n";
			update(1, 1, SZ, ans, -1);
		}
	}
}