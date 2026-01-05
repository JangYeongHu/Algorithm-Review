#include <cstdio>
bool arr[32][12];
int n, m, h;
bool possible() {
	for (int i = 1; i <= n; i++) {
		int now_x = i, now_y = 1;
		while (now_y <= h) {
			if (arr[now_y][now_x]) now_x++;
			else if (arr[now_y][now_x - 1]) now_x--;
			now_y++;
		}
		if (now_x != i) return 0;
	}
	return 1;
}

int check(int num, int now, int ind) {
	if (num == now) return possible();
	for (int i = ind; i < h * (n - 1); i++) {
		int y = i / (n - 1) + 1;
		int x = i % (n - 1) + 1;
		if (arr[y][x] || arr[y][x - 1] || arr[y][x + 1]) continue;
		arr[y][x] = 1;
		if (check(num, now + 1, i + 1)) return 1;
		arr[y][x] = 0;
	}
	return 0;
}

int main() {
	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	for (int i = 0; i < 4; i++)
		if (check(i, 0, 0)) { printf("%d", i); return 0; }
	printf("-1");
	return 0;
}