#include <cstdio>
int arr[10][10];
int cnt[] = {0,5,5,5,5,5};
int min = 26;
bool check(int x, int y, int n) {
	for (int j = 0; j < n; j++)
		for (int k = 0; k < n; k++) {
			if (y + j < 0 || y + j > 9 || x + k < 0 || x + k > 9) return 1;
			if (!arr[y + j][x + k]) return 1;
		}
	return 0;
}

void dfs(int ind,int res) {
	if (ind == 100 || res == min) {
		if (min > res) min = res;
		return;
	}
	int x = ind / 10, y = ind % 10;
	if (!arr[y][x]) dfs(ind + 1, res);
	for (int i = 1; i < 6; i++) {
		if (!cnt[i]) continue;
		if (check(x, y, i)) break;
		for (int j = 0; j < i; j++)
			for (int k = 0; k < i; k++)
				arr[y + j][x + k] = 0;
		cnt[i]--;
		dfs(ind + 1,res+1);
		for (int j = 0; j < i; j++)
			for (int k = 0; k < i; k++)
				arr[y + j][x + k] = 1;
		cnt[i]++;
	}
}

int main() {
	for (int i = 0; i < 100; i++) scanf("%d", &arr[i / 10][i % 10]);
	dfs(0,0);
	if (min == 26) printf("-1");
	else printf("%d", min);
	return 0;
}