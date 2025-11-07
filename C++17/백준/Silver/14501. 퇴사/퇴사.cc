#include <bits/stdc++.h>
using namespace std;
int T[15], P[15];
int dp[16];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> T[i] >> P[i];

    for (int i = 0; i < n; ++i) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        int nextDay = i + T[i];
        if (nextDay <= n)
            dp[nextDay] = max(dp[nextDay], dp[i] + P[i]);
    }

    cout << dp[n];
}

