#include <bits/stdc++.h>
using namespace std;
int dp[50001];
int n;

int fu(int x,int cnt) {
	if (dp[x] != 0) return dp[x];
	if (cnt == 4) return 100;
	int mn = 5;
	for (int i = 1; i * i < x; i++) {
		mn = min(mn, fu(x - i * i,cnt+1));
	}
	dp[x] = mn + 1;
	return mn + 1;
}

int main() {
	cin >> n;
	for (int i = 1; i*i <= n; i++) {
		dp[i * i] = 1;
	}

	cout << fu(n,0);
}