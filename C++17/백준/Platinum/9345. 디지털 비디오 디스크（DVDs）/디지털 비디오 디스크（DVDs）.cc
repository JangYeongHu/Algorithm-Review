#include <bits/stdc++.h>
using namespace std;

pair<int, int> tree[100001 * 4];
int arr[100001];

pair<int,int> init(int start, int end, int node) {
	if (start == end) { arr[start] = start; return tree[node] = { start,start }; }
	int mid = (start + end) / 2;
	auto a = init(start, mid, node * 2);
	auto b = init(mid + 1, end, node * 2 + 1);
	return tree[node] = { min(a.first, b.first),max(a.second,b.second) };
}

pair<int, int> update(int node, int start, int end, int num, int idx) {
	if (start > idx || end < idx) return tree[node];
	if (start == end) return tree[node] = { num,num };
	int mid = (start + end) / 2;
	auto a = update(node*2,start, mid, num,idx);
	auto b = update(node * 2+1, mid+1, end, num, idx);
	return tree[node] = { min(a.first, b.first),max(a.second,b.second) };
}

bool get(int node, int start, int end, int a, int b) {
	if (a > end || b < start) return true;
	if (tree[node].first >= a && tree[node].second <= b) return true;
	if (start == end) {
		if (tree[node].first < a || tree[node].second > b) return false;
		else return true;
	}
	
	int mid = (start + end) / 2;
	return get(node * 2, start, mid, a, b) && get(node * 2+1, mid+1, end, a, b);
}

void has_dvd() {
	int n,k;
	cin >> n >> k;
	init(1, n, 1);
	for (int i = 0; i < k; i++) {
		int q, a, b;
		cin >> q >> a >> b;
		a++; b++;
		if (q == 0) {
			int vala = arr[a], valb = arr[b];
			swap(arr[a], arr[b]);
			update(1, 1, n, vala, b); update(1, 1, n, valb, a);
		}
		else {
			if (get(1, 1, n, a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t-- > 0) {
		has_dvd();
	}
}