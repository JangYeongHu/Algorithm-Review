#include <iostream>
#include <queue>
using namespace std;
int arr[500][500];
int h, w, res = 0;
void bfs(int x, int y) {
	int t = x+1;
	while (t < w && arr[y][t] == 0) t++;
	if (t == w) return;
	for (int i = x + 1; i < t; i++) { arr[y][i] = 2; res++; }
	return;
}

int main() {
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		int t;
		cin >> t;
		for (int j = h - t; j < h; j++) {
			arr[j][i] = 1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j] == 1) bfs(j, i);
		}
	}
	cout << res;
	return 0;
}