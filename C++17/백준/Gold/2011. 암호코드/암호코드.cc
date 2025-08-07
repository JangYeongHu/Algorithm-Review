#include <cstdio>

using namespace std;
int arr[5001];
long long dp[5001];
int main() {
	int t, ind = 1;
	while (scanf("%1d", &t) != EOF) {
		arr[ind++] = t;
	}
	dp[0] = 1;
	if (arr[1] != 0) dp[1] = 1;

	for (int i = 2; i < ind; i++) {
		if (arr[i])dp[i] = dp[i - 1];
		if (arr[i - 1] * 10 + arr[i] < 27 && arr[i-1] > 0) dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}
	printf("%lld", dp[ind-1]);
	return 0;
}