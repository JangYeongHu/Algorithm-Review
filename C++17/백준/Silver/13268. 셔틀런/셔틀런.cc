#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	n %= 100;
	int ans;
	if (n == 0 || n == 10 || n == 30 || n == 60) {
		ans = 0;
	}
	else if ((0 < n && n < 10) || (10 < n && n <= 15) || (25 <= n && n < 30) || (30 < n && n <= 35) || (55 <= n && n < 60) || (60 < n && n <= 65) || (95 <= n && n < 100)) {
		ans = 1;
	}
	else if ((15 < n && n < 25) || (35 < n && n <= 40) || (50 <= n && n < 55) || (65 < n && n <= 70) || (90 <= n && n < 95)) {
		ans = 2;
	}
	else if ((40 < n && n < 50) || (70 < n && n <= 75) || (85 <= n && n < 90)) {
		ans = 3;
	}
	else {
		ans = 4;
	}
	cout<<ans;
	return 0;
}