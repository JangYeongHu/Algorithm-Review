#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main(){
	int n, m,res = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1;i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int t;
			scanf("%1d", &t);
			if (t) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				res = max(dp[i][j], res);
			}
		}
	}
	printf("%d", res*res);
	return 0;
}