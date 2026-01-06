#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[32][8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll K;
    cin >> N >> K;
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j] += dp[i - 1][j ^ (1<<k)];
            }
        }
    }

    int cur = 0;

    for (int i = N; i >= 1; i--) {
        ll cnt[3] = { 0, 0, 0 };

        for (int k = 0; k < 3; k++) {
            int next = cur ^ (1<<k);
            for (int j = 1; j < 8; j++)
                cnt[k] += dp[i - 1][j ^ next];
        }

        for (int k = 0; k < 3; k++) {
            if (K <= cnt[k]) {
                cout << 7-2*k;
                cur ^= (1<<k);
                break;
            } else {
                K -= cnt[k];
            }
        }
    }

    return 0;
}