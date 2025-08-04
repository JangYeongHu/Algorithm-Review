#include <bits/stdc++.h>
using namespace std;

int dp[21][1001];

int main() {
	int c, n; cin >> c >> n;
	for (int i = 0; i <= c; i++) dp[0][i] = 1 << 29;
	for(int i = 1; i <= n; i++) {
		int co, cl; cin >> co >> cl;
		for (int j = 1; j <= c; j++) {
			if (j - cl < 0) dp[i][j] = min(co,dp[i-1][j]);
			else dp[i][j] = min(dp[i][j-cl] + co,dp[i-1][j]);
		}
	}
	cout << dp[n][c];
}