#define MAX 1000000
#include <iostream>
using namespace std;
int dp[MAX];
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int a = dp[i - 1];
		int b = i % 3 ? MAX : dp[i / 3];
		int c = i % 2 ? MAX : dp[i / 2];
		dp[i] = min(a, min(b, c))+1;
	}
	cout << dp[n];
	return 0;
}