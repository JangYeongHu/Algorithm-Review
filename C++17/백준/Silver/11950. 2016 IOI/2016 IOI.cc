#include <bits/stdc++.h>
using namespace std;
string mp[50];
int n, m;
int check(char color,int a,int b) {
	int ans = 0;
	for (int i = a; i < b; i++)
		for (int j = 0; j < m; j++)
			if (mp[i][j] != color) ans++;
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> mp[i];
	int ans = 2501;
	for (int a = 1; a < n - 1; a++)
		for (int b = a+1; b < n; b++) {
			int cnt = check('W', 0, a) + check('B', a, b) + check('R', b, n);
			ans = min(cnt, ans);
		}
	cout << ans;
	return 0;
}