#include <bits/stdc++.h>
using namespace std;
double dp[21][3001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    double w, l, d;
    cin >> w >> l >> d;

    int st = 2000;
    dp[0][st] = 1.0;

    for (int i = 1; i <= 20; i++) {
        for (int j = 1000; j <= 3000; j++) {
            if (dp[i - 1][j] == 0) continue;
            dp[i][j + 50] += dp[i - 1][j] * w;
            dp[i][j - 50] += dp[i - 1][j] * l;
            dp[i][j] += dp[i - 1][j] * d;
        }
    }

    double ans[5] = {};
    int ranges[5][2] = {
        {1000, 1500},
        {1500, 2000},
        {2000, 2500},
        {2500, 3000},
        {3000, 3500}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = ranges[i][0]; j < ranges[i][1]; j++) {
            ans[i] += dp[20][j];
        }
    }

    for (int i = 0; i < 5; i++)
        cout << fixed << setprecision(8) << ans[i] << "\n";
}