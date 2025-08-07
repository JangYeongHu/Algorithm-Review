#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
int arr[1'000'001];

int main() {
	int n; cin >> n;
	int idx = 1;
	dp.push_back(1);
	while (dp.back() <= n)
		dp.push_back(dp.back() + 1 + 4 * idx++);
	for (int i = 1; i <= n; i++) {
		int idx = 0;
		int mn = 1 << 29;
		while (dp[idx] <= i)
			mn = min(mn, arr[i - dp[idx++]]);
		arr[i] = mn+1;
	}

	cout << arr[n];

	return 0;
}