#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct node { long long idx, s_idx, val; };
node x[200001];
pair<long long,long long> tree[200000 * 4];

pair<long long,long long> get_tree(int start, int end, int node, int left, int right) {
	if (right < start || left > end) return { 0,0 };
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	auto a = get_tree(start, mid, node * 2, left, right);
	auto b = get_tree(mid + 1, end, node * 2 + 1, left, right);
	return { a.first + b.first,a.second + b.second };
}

pair<long long, long long> update(int start, int end,int node, int idx, int num) {
	if (start > idx || end < idx) return tree[node];
	if (start == end) return tree[node] = { num,1 };
	int mid = (start + end) / 2;
	auto a = update(start, mid, node * 2, idx, num);
	auto b = update(mid + 1, end, node * 2 + 1, idx, num);
	return tree[node] = { a.first + b.first,a.second + b.second };
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		x[i] = {i ,0, a};
	}

	sort(x, x + n,
		[](node a, node b) -> bool {
			return a.val < b.val;
		});
	for (int i = 0; i < n; i++) {
		x[i].s_idx = i+1;
	}
	sort(x, x + n,
		[](node a, node b) -> bool {
			return a.idx < b.idx;
		});

	long long res = 1;
	update(1, n, 1, x[0].s_idx, x[0].val);
	for (int i = 1; i < n; i++) {
		long long t = 0;
		int idx = x[i].s_idx;
		auto a = get_tree(1, n, 1, idx + 1, n);
		t = (t + a.first - x[i].val * a.second)%MOD;
		a = get_tree(1, n, 1, 1, idx - 1);
		t = (t - a.first + x[i].val * a.second)%MOD;
		update(1, n, 1, idx, x[i].val);
		res = (res * t) % MOD;
	}
	cout << res;
}