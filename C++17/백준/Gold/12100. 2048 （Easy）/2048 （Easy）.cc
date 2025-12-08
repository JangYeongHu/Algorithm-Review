#include <cstdio>
int n,res = 0;

void move_l(int arr[][20]) {
	bool vis[20][20] = { 0, };
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int now = i;
			if (!arr[j][now]) continue;

			while (now > 0) {
				if (arr[j][now - 1] == arr[j][now])
					if (vis[j][now - 1]) break;
					else {arr[j][now - 1] *= 2; vis[j][now - 1] = 1; arr[j][now] = 0; break; }
				else if (arr[j][now - 1] != arr[j][now] && arr[j][now-1]) break;
				arr[j][now - 1] = arr[j][now];
				arr[j][now] = 0;
				now--;
			}
		}
	}
}
void move_r(int arr[][20]) {
	bool vis[20][20] = { 0, };
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			int now = i;
			if (!arr[j][now]) continue;

			while (now < n-1) {
				if (arr[j][now + 1] == arr[j][now])
					if (vis[j][now + 1]) break;
					else { arr[j][now + 1] *= 2; vis[j][now + 1] = 1; arr[j][now] = 0; break; }
				else if (arr[j][now + 1] != arr[j][now] && arr[j][now + 1]) break;
				arr[j][now + 1] = arr[j][now];
				arr[j][now] = 0;
				now++;
			}
		}
	}
}


void move_u(int arr[][20]) {
	bool vis[20][20] = { 0, };
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int now = i;
			if (!arr[now][j]) continue;
			while (now > 0) {
				if (arr[now - 1][j] == arr[now][j])
					if (vis[now - 1][j]) break;
					else { arr[now-1][j] *= 2; vis[now - 1][j] = 1; arr[now][j] = 0; break; }
				else if (arr[now - 1][j] != arr[now][j] && arr[now - 1][j]) break;
				arr[now - 1][j] = arr[now][j];
				arr[now][j] = 0;
				now--;
			}
		}
	}
}

void move_d(int arr[][20]) {
	bool vis[20][20] = { 0, };
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			int now = i;
			if (!arr[now][j]) continue;
			while (now < n-1) {
				if (arr[now + 1][j] == arr[now][j])
					if (vis[now + 1][j]) break;
					else { arr[now + 1][j] *= 2; vis[now + 1][j] = 1; arr[now][j] = 0; break; }
				else if (arr[now + 1][j] != arr[now][j] && arr[now + 1][j]) break;
				arr[now + 1][j] = arr[now][j];
				arr[now][j] = 0;
				now++;
			}
		}
	}
}

void (*fp[4])(int[][20]) = { move_l,move_r,move_u,move_d };

void dfs(int cnt,int a[][20]) {
	if (cnt ==	5) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				res = res > a[i][j] ? res : a[i][j];
		return;
	}
	for (int k = 0; k < 4; k++) {
		int b[20][20];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				b[i][j] = a[i][j];
		fp[k](b);
		dfs(cnt + 1, b);
	}
}

int main() {
	int arr[20][20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	if (n == 1) { printf("%d", arr[0][0]); return 0; }
	dfs(0, arr);
	printf("%d", res);
	return 0;
}