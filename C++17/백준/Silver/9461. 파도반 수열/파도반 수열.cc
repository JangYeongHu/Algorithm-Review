#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
long long dp[101];
int main() {
	int t;
	cin >> t;
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= 101; i++) dp[i] = dp[i - 2] + dp[i - 3];
	while (t-- > 0) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}