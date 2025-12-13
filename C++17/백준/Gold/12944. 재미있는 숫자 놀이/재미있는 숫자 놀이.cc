#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> v;

    for (int i = 0; i < k; i++) {
        ll t; cin >> t;
        if(t == 1) {
            cout << n;
            return 0;
        }
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    k = v.size();

    ll ans = 0;

    for (int i = 1; i < (1LL << k); i++) {
        ll num = 1, cnt = 0;
        bool overflow = false;

        for (int j = 0; j < k; j++) {
            if ((1LL << j) & i) {
                num = lcm(num,v[j]);
                if(num>n) {
                    overflow=1;
                    break;
                }
                cnt++;
            }
        }

        if (overflow || num > n) continue;

        if (cnt & 1) ans += n / num;
        else ans -= n / num;
    }

    cout << ans;
    return 0;
}