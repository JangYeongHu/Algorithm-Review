#include <bits/stdc++.h>
using namespace std;

int main() {
	while (1) {
		double n, b, m; cin >> n >> b >> m;
		if (cin.eof()) break;
		double now = n;
		int cnt = 0;
		while (now < m) {
			now += now/100*b;
			cnt++;
		}
		cout << cnt << "\n";
	}
}