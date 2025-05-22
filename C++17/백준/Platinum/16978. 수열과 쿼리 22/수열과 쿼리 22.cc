#include <bits/stdc++.h>

struct Node {
	Node *l,* r;
	long long v;
	Node() { v = 0; l = r = NULL; }
};
using namespace std;
int arr[100001];

vector<Node*> roots;



void init(int s, int e, Node* node) {
	if (s == e) {
		node->v = arr[s];
		return;
	}
	node->l = new Node();
	node->r = new Node();
	int m = (s + e) / 2;
	init(s, m, node->l);
	init(m + 1, e, node->r);
	node->v = node->l->v + node->r->v;
}

void update(Node* pre, Node* cur,int s, int e,int i, int x) {
	if (s == e) {
		cur->v = x;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m) {
		cur->l = new Node();
		cur->r = pre->r;
		update(pre->l, cur->l, s, m, i, x);
	}
	else {
		cur->l = pre->l;
		cur->r = new Node();
		update(pre->r , cur->r, m+1, e, i, x);
	}
	cur->v = cur->l->v + cur->r->v;
}

long long get(int s, int e, Node* n, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return n->v;
	int m = (s + e) / 2;
	return get(s, m, n->l, l, r) + get(m + 1, e, n->r, l, r);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	roots.push_back(new Node());
	init(1, n, roots.back());

	int m; cin >> m;
	while (m-- > 0) {
		int a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			Node* pre = roots.back();
			Node* cur = new Node();
			roots.push_back(cur);
			update(pre,cur,1,n,b,c);
		}
		else {
			cin >> d;
			cout << get(1, n, roots[b], c, d) << "\n";
		}
	}


	return 0;
}