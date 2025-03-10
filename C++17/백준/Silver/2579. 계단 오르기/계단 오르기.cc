#include <bits/stdc++.h>
using namespace std;
int stairs[301];
int dp[301];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
		dp[i] = stairs[i];
	}

	dp[2] += stairs[1];

	for (int i = 3; i <= n; i++)
		dp[i] += max(stairs[i - 1] + dp[i - 3], dp[i-2]);

	cout << dp[n];
}