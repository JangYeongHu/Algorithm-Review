#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 1 << 20;
ll T[SZ << 1];

void Set(int x, ll v) { // x번째 수를 v로 지정, x는 0 이상 SZ 미만
    x += SZ; T[x] = v;
    while (x /= 2) T[x] = max(T[x * 2],T[x * 2 + 1]);
}

ll Max(int l, int r) { // [l, r] 구간의 합
    ll res = 0;
    for (l += SZ, r += SZ; l <= r; l /= 2, r /= 2) {
        if (l % 2 == 1) res = max(res,T[l++]);
        if (r % 2 == 0) res = max(res,T[r--]);
    }
    return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t; cin >> t; 
        Set(i, t);
    }

    int window = 2 * m - 1;

    for (int i = 0; i < n - window+1; i++)
        cout << Max(i, i + window - 1) << " ";

}

