#include <cstdio>
int gate[100000];

int find(int x) {
	if (gate[x] == x) return x;
	gate[x] = find(gate[x]);
	return gate[x];
}

bool uni(int x) {
	x = find(x);
	int y = find(x-1);
	if (x == 0) return 1;
	gate[x] = y;
	return 0;
}

int main() {
	int g, p, res = 0;
	scanf("%d", &g);
	scanf("%d", &p);
	for (int i = 0; i <= g; i++) gate[i] = i;
	for (int i = 0; i < p; i++) {
		int ind;
		scanf("%d", &ind);
		if (uni(ind)) break;
		res++;
	}
	printf("%d", res);
	return 0;
}