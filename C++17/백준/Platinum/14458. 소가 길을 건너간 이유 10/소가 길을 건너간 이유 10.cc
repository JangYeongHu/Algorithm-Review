#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];
int tree[100001 * 4];
unordered_map<int, int> um;
unordered_map<int, int> uma;
unordered_map<int, int> umb;

int get(int s, int e, int n, int l,int r) {
	if (s > r || e < l || s > e) return 0;
	if (l <= s && r >= e) return tree[n];
	int m = (s + e) / 2;
	return get(s, m, n * 2, l, r) + get(m+1, e, n * 2+1, l, r);
}

void update(int s, int e, int n, int k) {
	if (s == e) { tree[n] = 1; return; }
	int m = (s + e) / 2;
	if (m >= k) update(s, m, n * 2, k);
	else update(m+1, e, n * 2+1, k);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		uma.insert({ a[i],i });
}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		um.insert({ b[i],i });
		umb.insert({ i,b[i]});
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += get(1, n, 1, um[a[i]]+1, n);
		update(1, n, 1, um[a[i]]);
	}
	long long res1,res2,ans1 = ans;
	res1 = res2 = ans;
	for (int i = 1; i <= n; i++) {
		int x = um[a[i]];
		ans += n - x - x + 1;
		res1 = min(ans, res1);
	}

	for (int i = 1; i <= n; i++) {
		int x = uma[b[i]];
		ans1 += n - x - x + 1;
		res2 = min(ans1, res2);
	}

	cout << min(res1, res2);
}