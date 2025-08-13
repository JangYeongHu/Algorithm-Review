#include <bits/stdc++.h>
using namespace std;
int arr[100'000];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int ans = 0,sum = 0;
	for (int i = n-1; i >= 0; i--) {
		sum += arr[i];
		int b = min(arr[i], sum / (i + 1));
		ans = max(ans,b*(n-i));
	}

	cout << ans;

	return 0;
}