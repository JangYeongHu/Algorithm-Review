#include <bits/stdc++.h>
using namespace std;
bool arr[32][12];
int N,M,H;
bool possible() {
	for (int i = 1; i <= N; i++) {
		int x = i, y = 1;
		while (y <= H) {
			if (arr[y][x]) x++;
			else if (arr[y][x - 1]) x--;
			y++;
		}
		if (x != i) return 0;
	}
	return 1;
}

bool check(int num, int now, int idx) {
	if (num == now) return possible();
	for (int i = idx; i < H * (N - 1); i++) {
		int y = i / (N - 1) + 1;
		int x = i % (N - 1) + 1;
		if (arr[y][x] || arr[y][x - 1] || arr[y][x + 1]) continue;
		arr[y][x] = 1;
		if (check(num, now + 1, i + 1)) return 1;
		arr[y][x] = 0;
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int i = 0; i < 4; i++)
		if (check(i, 0, 0)) {
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}