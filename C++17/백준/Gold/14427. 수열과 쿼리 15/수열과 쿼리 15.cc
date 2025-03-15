#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int tree[100001*4];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;
	int l = init(start, mid, node * 2);
	int r = init(mid + 1, end, node * 2 + 1);
	if (arr[l] < arr[r] || (arr[l] == arr[r] && l < r)) return tree[node] = l;
	else return tree[node] = r;
}

int update(int start, int end, int node, int ind) {
	if (start > ind || end < ind) return tree[node];
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;
	int l = update(start, mid, node * 2, ind);
	int r = update(mid + 1, end, node * 2 + 1, ind);
	if (arr[l] < arr[r] || (arr[l] == arr[r] && l < r)) return tree[node] = l;
	else return tree[node] = r;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, n, 1);
	arr[0] = 1<<29;

	int m;
	cin >> m;
	while (m-- > 0) {
		int q;
		cin >> q;
		if (q == 2) cout << tree[1] << "\n";
		else {
			int v, i;
			cin >> i >> v;
			arr[i] = v;
			update(1, n,1, i);
		}
	}
}