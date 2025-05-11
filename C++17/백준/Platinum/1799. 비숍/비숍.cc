#include <bits/stdc++.h>
using namespace std;
int board[10][10];
int n;

bool check(int x, int y) {
	int ind = 1;
	while (1) {
		if (x + ind >= n || y + ind >= n) break;
		if (board[ind + y][ind + x] == 2) return 1;
		ind++;
	}
	ind = 1;
	while (1) {
		if (x - ind < 0 || y - ind < 0) break;
		if (board[y - ind][x - ind] == 2) return 1;
		ind++;
	}
	return 0;
}

int brute(int a) {
	if (a > n * 2-2) return 0;
	int x = 0, y = 0, mx = brute(a+2);
	if (a / n == 0) {
		y = 0, x = a;
	}
	else {
		x = n - 1; y = a - x;
	}
	while (1) {
		if (x < 0 || y >= n) break;
		if (board[y][x] != 1 || check(x, y)) { x--; y++; continue; }
		board[y][x] = 2;
		mx = max(mx,brute(a + 2) + 1);
		board[y][x] = 1;
		x--; y++;
	}
	return mx;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	cout << brute(0) + brute(1);
	return 0;
}