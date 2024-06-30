#include <cstdio>

#define ABS(x) ((x)>0?(x):-(x))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int dp[5][5][100001];

int check(int a,int n) {
	if (a == 0) return 2;
	if (ABS(a - n) == 1 || ABS(a - n) == 3) return 3;
	if (ABS(a - n) == 2) return 4;
	return 1;
}

int main() {
	int n,cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < 100001; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				dp[j][k][i] = 1 << 30;
	dp[0][0][0] = 0;
	while (n != 0) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				dp[i][n][cnt+1] = MIN(dp[i][n][cnt+1],dp[i][j][cnt] + check(j,n));
				dp[n][j][cnt + 1] = MIN(dp[n][j][cnt + 1], dp[i][j][cnt] + check(i, n));
			}
		scanf("%d", &n);
		cnt++;
	}
	int res = 1<<30;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (dp[i][j][cnt] != 1<<30) res = MIN(res, dp[i][j][cnt]);
	printf("%d", res);
	return 0;
}