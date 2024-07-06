#include <iostream>
#include <algorithm>
#define MAX 4000001

using namespace std;

int card[MAX];
int parent[MAX];
int height[MAX];

int find(int x) {
	while (parent[x] != x) x = parent[x];
	return x;
}

void tree_union(int a) {
	a = find(a);
	cout << card[a] << "\n";
	parent[a] = a + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) cin >> card[i];
	sort(card, card + m);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < k; i++) {
		int number;
		cin >> number;
		int start = 0, end = m-1, mid;
		int mx = end;
		while (start <= end) {
			mid = (start + end) / 2;
			if (card[mid] > number) {
				if (card[mx] > card[mid]) mx = mid;
				end = mid - 1;
			}
			else start = mid + 1;
		}
		tree_union(mx);
	}
	return 0;
}