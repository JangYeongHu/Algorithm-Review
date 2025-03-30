#include <bits/stdc++.h>
using namespace std;
int dp[2501];
string str;
bool is_pal(int s, int e) {
	while (str[s] == str[e] && s < e) { s++; e--; }
	if (s < e) return 0;
	return 1;
}

int main() {
	cin >> str;
	int l = str.length();
	for (int i = 0; i <= l; i++) dp[i] = 1<<28;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 1; i < l; i++)
		for (int j = i; j >= 0; j--)
			if (is_pal(j, i)) dp[i+1] = min(dp[i+1], dp[j] + 1);

	cout << dp[l];
}