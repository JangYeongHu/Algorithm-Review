#include <bits/stdc++.h>
using namespace std;
pair<int,int> arr[500001];
long long tree[500001 * 4];

long long get(int start, int end, int node, int left,int right) {
	if (right < start || left > end) return 0;
	if (end <= right && start >= left) return tree[node];
	int mid = (start + end) / 2;
	return get(start, mid, node * 2, left, right) + get(mid + 1, end, node * 2 + 1, left, right);
}

long long update(int start, int end, int node, int ind) {
	if (start > ind || end < ind) return tree[node];
	if (start == end) return tree[node] = 1;
	int mid = (start + end) / 2;
	return tree[node] = update(start, mid, node * 2, ind) + update(mid + 1, end, node * 2 + 1, ind);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = { a,i+1 };
	}
	sort(arr, arr + n);
	long long res = 0;
	for (int i = 0; i < n; i++) {
		int ind = arr[i].second;
		res += get(1, n, 1, ind+1, n);
		update(1, n, 1, ind);
	}
	cout << res;
}