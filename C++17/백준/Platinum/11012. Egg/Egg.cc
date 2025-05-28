#include <bits/stdc++.h>

struct Node {
	Node* l, * r;
	long long v;
	Node() { v = 0; l = r = NULL; }
};
using namespace std;

vector<Node*> roots;

void init(int s, int e, Node* node) {
	if (s == e) {
		return;
	}
	node->l = new Node();
	node->r = new Node();
	int m = (s + e) / 2;
	init(s, m, node->l);
	init(m + 1, e, node->r);
}

void update(Node* pre, Node* cur, int s, int e, int i) {
	if (s == e) {
		cur->v = pre->v + 1;
		return;
	}
	int m = (s + e) / 2;
	if (i <= m) {
		cur->l = new Node();
		cur->r = pre->r;
		update(pre->l, cur->l, s, m, i);
	}
	else {
		cur->l = pre->l;
		cur->r = new Node();
		update(pre->r, cur->r, m + 1, e, i);
	}
	cur->v = cur->l->v + cur->r->v;
}

long long get(int s, int e, Node* n, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return n->v;
	int m = (s + e) / 2;
	return get(s, m, n->l, l, r) + get(m + 1, e, n->r, l, r);
}

int solve() {
	int n, m; cin >> n >> m;
	roots.push_back(new Node());
	init(0, 100000, roots.back());
	vector<pair<int, int>> points;
	vector<Node*> xs(100001, NULL);
	xs[0] = roots.back();
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		points.push_back({ x,y });
	}
	sort(points.begin(), points.end());
	for(auto [x,y]: points) {
		roots.push_back(new Node());
		xs[x] = roots.back();
		update(roots[roots.size() - 2], xs[x], 0, 100000, y);
	}
	int idx = 0;
	for (int i = 0; i <= 100000; i++) {
		if (xs[i] == NULL) xs[i] = xs[i - 1];
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int l, r, b, t;
		cin >> l >> r >> b >> t;
		ans += get(0, 100000, xs[r], b, t);
		if(l>0)ans-=get(0, 100000, xs[l - 1], b, t);
	}
	return ans;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) {
		roots.clear();
		cout << solve() << "\n";
	}

	return 0;
}