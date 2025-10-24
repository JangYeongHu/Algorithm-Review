#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int mn = 1<<30, mx = 1;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		mn = min(t, mn);
		mx = max(t, mx);
	}
	cout << mn * mx;
}