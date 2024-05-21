#include <cstdio>
#include <queue>
std::vector<int> v[50001];
int parent[50001][20];
int height[50001];
int square[20];
int n, m;

void tree(int pparent, int parentn) {
	for (auto iter = v[parentn].begin(); iter != v[parentn].end(); iter++) {
		int child = *iter;
		if (pparent == child) continue;
		height[child] = height[parentn] + 1;
		parent[child][0] = parentn;
		int ind = 1;
		while (square[ind] <= n) {
			parent[child][ind] = parent[parent[child][ind-1]][ind - 1];
			ind++;
		}
		tree(parentn, child);
	}
}

int main() {
	scanf("%d", &n);
	square[0] = 1;
	for (int i = 1; i < 20; i++) square[i] = square[i-1]* 2;
	for (int i = 1; i < n; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		v[s].push_back(e);
		v[e].push_back(s);
	}
	tree(-1, 1);
	scanf("%d", &m);
	while(m-->0) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (height[b] > height[a]) std::swap(a, b);
		while (height[a] != height[b]) {
			int ind = 0;
			while (square[ind + 1] < height[a] - height[b]) ind++;
			a = parent[a][ind];
		}
		while (a != b) {
			int ind = 0;
			while (parent[a][ind+1] != parent[b][ind+1]) ind++;
			a = parent[a][ind]; b = parent[b][ind];
		}
		printf("%d\n", a);
	}
	return 0;
}