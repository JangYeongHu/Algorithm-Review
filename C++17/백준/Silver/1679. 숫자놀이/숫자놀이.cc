#include <bits/stdc++.h>
using namespace std;

int dp[50002];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int arr[1000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k; cin >> k;

    for (int i = 1; i <= arr[n - 1] * k; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (arr[j] <= i)
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
        if (dp[i] > k) {
            cout << ((i & 1) ? "jjaksoon" : "holsoon") << " win at " << i;
            return 0;
        }
    }
}