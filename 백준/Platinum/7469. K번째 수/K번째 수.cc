#include <bits/stdc++.h>
using namespace std;
int arr[100001];
vector<int> tree[100001 * 4];

void init(int s, int e, int n) {
	if (s == e) {
		tree[n].push_back(arr[s]);
		return;
	}
	int m = (s + e) / 2;
	int l_n = n * 2, r_n = l_n + 1;
	int lind = 0, rind = 0;
	init(s, m, l_n);
	init(m + 1, e, r_n);
	auto larr = tree[l_n];
	auto rarr = tree[r_n];
	while (larr.size() > lind && rarr.size() > rind) {
		if (larr[lind] < rarr[rind]) {
			tree[n].push_back(larr[lind++]);
		}
		else {
			tree[n].push_back(rarr[rind++]);
		}
	}
	while(larr.size() > lind) tree[n].push_back(larr[lind++]);
	while (rarr.size() > rind) tree[n].push_back(rarr[rind++]);
}

int get(int s, int e, int n, int l, int r,long long k) {
	if (r < s || l > e	) return 0;
	if (s >= l && e <= r) {
		int res = upper_bound(tree[n].begin(), tree[n].end(), k) - tree[n].begin();
		return res;
	}
	int m = (s + e) / 2;
	return get(s, m, n * 2, l, r, k) + get(m+1, e, n * 2+1, l, r, k);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i + 1];

	init(1, n, 1);

	while (m-- > 0) {
		int a, b, k;
		cin >> a >> b >> k;
		long long start = -1e9,end = 1e9,mid;
		long long ans = end;
		while (start <= end) {
			mid = (start + end) / 2;
			int res = get(1, n, 1, a, b, mid);
			if (res >= k) {
				ans = min(ans, mid);
				end = mid - 1;
			}
			else start = mid + 1;
		}
		cout << ans << "\n";
	}
}