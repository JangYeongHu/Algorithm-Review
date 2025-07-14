#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	long long sum = 0, mn = 1LL<<60;
	for (int i = 0; i < n*m; i++) {
		long long t; cin >> t;
		sum += t; mn = min(t, mn);
	}
	cout << sum - mn;
	return 0;
}