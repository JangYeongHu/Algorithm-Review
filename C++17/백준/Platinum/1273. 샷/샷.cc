#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 1<<22;
ll T[SZ << 1];
ll arr[SZ];
int point[] = { 1,2,5 };

void Set(int x, ll v) {
    x += SZ; T[x] = v;
    while (x /= 2) T[x] = T[x * 2] + T[x * 2 + 1];
}

int Kth(ll k) {
    int node = 1;
    if (T[node] < k) return -1;
    while (node < SZ) {
        if (T[node * 2] >= k) {
            node = node * 2;
        }
        else {
            k -= T[node * 2];
            node = node * 2 + 1;
        }
    }
    return node - SZ;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> now(n,0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            arr[now[j]] += point[i];
            arr[now[j] + t] -= point[i];
            now[j] += t;
        }
    }

    for (int i = 1; i < SZ; i++) arr[i] += arr[i - 1];

    for (int i = 0; i < SZ; i++)
        Set(i, 1);

    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        int x = Kth(t);
        if (x < 0) cout << "0\n";
        else {
            cout << arr[x] << "\n";
            Set(x, 0);
        }
    }

    return 0;
}