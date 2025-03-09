#include <iostream>
using namespace std;
int w[16][16];
int dp[16][1 << 16];
int n;
int tsp(int x,int idx) {

	if (idx == (1 << n) - 1) return w[x][0]!=0 ? w[x][0] : 1<<29;
	if (dp[x][idx] != -1) return dp[x][idx];
	dp[x][idx] = 1 << 29;
	for (int i = 0; i < n; i++) {
		if ((idx & (1 << i)) || w[x][i] == 0) continue;
		int t = tsp(i, idx | (1 << i)) + w[x][i];
		if (t < dp[x][idx]) dp[x][idx] = t;
	}
	return dp[x][idx];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
		for (int j = 0; j < (1 << 16); j++) dp[i][j] = -1;
	}
	cout << tsp(0,1);

	return 0;
}