#include <bits/stdc++.h>
using namespace std;
int mp[2][3], dp[2][3][2];

int main() {
	int n;
	cin >> n;
	cin >> mp[0][0] >> mp[0][1] >> mp[0][2];
	for (int j = 0; j < 3; j++) dp[0][j][0] = dp[0][j][1] = mp[0][j];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) cin >> mp[1][j];
		for (int j = 0; j < 3; j++) dp[1][j][0] = dp[1][j][1] = mp[1][j];
		dp[1][0][0] += max(dp[0][0][0], dp[0][1][0]);
		dp[1][0][1] += min(dp[0][0][1], dp[0][1][1]);

		dp[1][1][0] += max(max(dp[0][0][0], dp[0][1][0]),dp[0][2][0]);
		dp[1][1][1] += min(min(dp[0][0][1], dp[0][1][1]), dp[0][2][1]);

		dp[1][2][0] += max(dp[0][2][0], dp[0][1][0]);
		dp[1][2][1] += min(dp[0][2][1], dp[0][1][1]);

		for (int j = 0; j < 3; j++) { dp[0][j][0] = dp[1][j][0]; dp[0][j][1] = dp[1][j][1];}
	}
	cout << max(max(dp[0][0][0], dp[0][1][0]), dp[0][2][0]) << " " << min(min(dp[0][0][1], dp[0][1][1]), dp[0][2][1]);
}