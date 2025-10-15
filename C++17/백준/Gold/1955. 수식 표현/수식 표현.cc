#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int main() {
	int n; cin >> n;
	int now = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if(dp[i] == 0) dp[i] = dp[i - 1] + 1;
		for (int j = 2; j < i; j++) {
			dp[i] = min(dp[i], dp[j] + dp[i-j]);
			if (i % j == 0 && i/j >= j) {
				dp[i] = min(dp[i], dp[i / j] + dp[j]);
			}
		}
		if (now * i > n) continue;
		now *= i;
		dp[now] = dp[i];
	}
	cout << dp[n];
	return 0;
}