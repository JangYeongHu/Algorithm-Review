#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using pii = pair<int, int>;

int parent[100001];

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void unn(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (parent[a] > parent[b]) swap(a, b);
    parent[b] += parent[a];  parent[a] = b;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector<pii> nodes;
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        pii a;
        cin >> a.first >> a.second;
        nodes.push_back(a);
    }

    vector<int> dj;
    unordered_set<int> ds;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        dj.push_back(t-1);
        ds.insert(t-1);
    }

    for (int i = 0; i < m; i++)
        if (ds.find(i) == ds.end())
            unn(nodes[i].first, nodes[i].second);

    reverse(dj.begin(), dj.end());

    long long ans = 0;
    for (auto t : dj) {
        int f = find(nodes[t].first);
        int s = find(nodes[t].second);
        if (f == s) continue;
        ans += parent[f] * parent[s];
        unn(f, s);
    }

    cout << ans;

    return 0;
}