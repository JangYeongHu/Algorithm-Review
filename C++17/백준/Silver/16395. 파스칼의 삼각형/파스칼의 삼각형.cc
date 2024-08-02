#include <iostream>
using namespace std;
int dp[30][30];
int main(){
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) dp[i][0] = dp[0][i] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	cout << dp[n - k][k - 1];
	return 0;
}