#include <iostream>
using namespace std;
int dp[1001];
int a[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 0; j <= i; j++) {
			if (a[j] < a[i]) mx = max(mx, dp[j] + 1);
		}
		dp[i] = mx;
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, dp[i]);
	}
	cout << res;

	return 0;
}