#include <bits/stdc++.h>
using namespace std;
int dp[500][500];
int main() {
	int n;
	cin >> n;
	cin >> dp[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
			if (j == 0) dp[i][j] += dp[i - 1][j];
			else if (j == i) dp[i][j] += dp[i - 1][i-1];
			else dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) res = max(res, dp[n-1][i]);
	cout << res;
}