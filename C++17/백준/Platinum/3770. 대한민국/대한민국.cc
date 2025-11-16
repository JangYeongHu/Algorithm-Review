#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 1 << 20;
ll T[SZ << 1];

void Set(int x,int v) {
    x += SZ; T[x]+=v;
    while (x /= 2) T[x] = T[x * 2] + T[x * 2 + 1];
}

ll Sum(int l, int r) {
    ll res = 0;
    for (l += SZ, r += SZ; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res += T[l++];
        if (r % 2 == 0) res += T[r--];
    }
    return res;
}

ll solve() {
    int n, m, k; cin >> n >> m >> k;
    ll ans = 0;
    vector<pair<int, int>> bridges;
    while (k--) {
        int a, b; cin >> a >> b;
        b--;
        bridges.push_back({ a,b });
    }
    sort(bridges.begin(), bridges.end());

    for (auto [a, b] : bridges) {
        ans += Sum(b + 1, m-1);
        Set(b,1);
    }

    for (auto [a, b] : bridges) Set(b,-1);

    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i = 1; i <= t; i++)
        cout << "Test case " << i << ": " << solve() << "\n";
}
