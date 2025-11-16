#include <bits/stdc++.h>
using namespace std;

bool dp[64][64];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            if (dp[i][j] == 0) continue;
            if (t == -1) {
                cout << "HaruHaru";
                return 0;
            }
            if (i + t < n) dp[i + t][j] = 1;
            if (j + t < n) dp[i][j+t] = 1;
        }

    cout << "Hing";
    return 0;
}