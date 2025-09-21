#include <bits/stdc++.h>
using namespace std;
int arr[367];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		for (int j = a; j <= b; j++) arr[j]++;
	}

	int start = 0;
	int ans = 0,mx = 0;
	bool k = 0;
	for (int i = 1; i < 367; i++) {
		if (arr[i] == 0) {
			if (k) {
				ans += (i - start-1) * mx;
			}
			k = 0;
			mx = 0;
			start = i;
		} 
		else {
			k = 1;
			mx = max(mx, arr[i]);
		}
	}

	cout << ans;
}