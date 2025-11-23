#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 1 << 16;
ll T[SZ << 1], L[SZ << 1];
typedef struct { int s, e, m; } group;
int arr[20001];

void Push(int node, int s, int e) {
	if (L[node] == 0) return;
	T[node] += L[node];
	if (s != e) L[node * 2] += L[node], L[node * 2 + 1] += L[node];
	L[node] = 0;
}

void RangeAdd(int l, int r, ll v, int node = 1, int s = 0, int e = SZ - 1) {
	Push(node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) { L[node] += v; Push(node, s, e); return; }
	int m = (s + e) / 2;
	RangeAdd(l, r, v, node * 2, s, m);
	RangeAdd(l, r, v, node * 2+1, m+1, e);
	T[node] = max(T[node * 2], T[node * 2 + 1]);
}

ll RangeMax(int l, int r, int node = 1, int s = 0, int e = SZ - 1) {
	Push(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return T[node];
	int m = (s + e) / 2;
	return max(RangeMax(l, r, node * 2, s, m), RangeMax(l, r, node * 2 + 1, m + 1, e));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int k, n, c; cin >> k >> n >> c;
	vector<group> groups;
	for (int i = 0; i < k; i++) {
		group g; cin >> g.s >> g.e >> g.m;
		groups.push_back(g);
	}

    sort(groups.begin(), groups.end(), [](group a, group b) {
        if (a.e == b.e) return a.s < b.s;
        return a.e < b.e;
    });

	int ans = 0;
	int idx = 0;
    for (auto& g : groups) {
        ll max_passengers = RangeMax(g.s, g.e - 1);

        ll can_take = min((ll)g.m, c - max_passengers);

        if (can_take > 0) {
            ans += can_take;
            RangeAdd(g.s, g.e - 1, can_take);
        }
    }

    cout << ans << "\n";

	return 0;
}