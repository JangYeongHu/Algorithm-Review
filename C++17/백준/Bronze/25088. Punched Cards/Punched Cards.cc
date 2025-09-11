#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (i == 0 && j == 0) cout << "..";
			else cout << "+-";
		cout << "+\n";
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) cout << "..";
			else cout << "|.";
		}
		cout << "|\n";
	}
	for (int j = 0; j < m; j++) cout << "+-";
	cout << "+\n";
}

int main() {
	int t; cin >> t;
	for(int i = 1; i <= t; i++) {
		int n, m; cin >> n >> m;
		cout << "Case #" << i << ":\n";
		solve(n, m);
	}
}