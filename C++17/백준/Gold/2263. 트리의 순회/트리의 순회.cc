#include <cstdio>
int ino[100000];
int posto[100000];
int index[100000];

void preo(int as,int ae,int bs,int be) {
	if (as > ae || bs > be) return;
	int root = be;
	printf("%d ", posto[root]);
	int lsize = index[root] - as;
	preo(as, as+lsize-1, bs, bs + lsize - 1);
	preo(index[root] + 1, ae , bs + lsize, be - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", ino + i);
	for (int i = 0; i < n; i++) scanf("%d", posto + i);
	for (int i = 0; i < n; i++) {
		int ind = 0;
		while (posto[i] != ino[ind++]);
		index[i] = ind-1;
	}
	preo(0, n - 1, 0, n - 1);
	return 0;
}