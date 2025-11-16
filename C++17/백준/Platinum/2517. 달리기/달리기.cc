#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 1 << 20;
ll T[SZ << 1];
ll arr[SZ];

void Set(int x, ll v) {
    x += SZ; T[x] = v;
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> C;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        C.push_back(arr[i]);
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(C.begin(), C.end(), arr[i]) - C.begin();
    }

    for (int i = 0; i < n; i++) {
        cout << Sum(arr[i]+1, n - 1)+1 << "\n";
        Set(arr[i], 1);
    }

    return 0;
}