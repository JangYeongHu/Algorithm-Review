#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
struct pos { int x, y;
static int ccw(pos a, pos b, pos c) {
	int res = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (res > 0) return 1;
	if (res < 0) return -1;
	return 0;
	}
};

bool operator<=(pos a, pos b) {
	if (a.x == b.x) return a.y <= b.y;
	return a.x <= b.x;
}

bool mn(pos x, pos y) {
	if (x.x == y.x) return x.y > y.y;
	return x.x > y.x;
}

pos lines[3000][2];
int parent[3000];
int weight[3000];

bool is_crossed(int a, int b) {

	pos p1 = lines[a][0], p2 = lines[a][1], p3 = lines[b][0], p4 = lines[b][1];

	if (mn(p1, p2)) swap(p1, p2);
	if (mn(p3, p4)) swap(p3, p4);


	int c1 = pos::ccw(p3, p1, p2) * pos::ccw(p4, p1, p2);
	int c2 = pos::ccw(p1, p3, p4) * pos::ccw(p2, p3, p4);
	if (c1 == 0 && c2 == 0) return p1 <= p4 && p3 <= p2;
	if (c1 > 0 || c2 > 0) return 0;
	return 1;
}

int find(int a) {
	while (parent[a] != a) a = parent[a];
	return a;
}

void unn(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[a] = b;
	weight[b] += weight[a];
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) weight[i] = 1;
	for (int i = 0; i < n; i++)
		cin >> lines[i][0].x >> lines[i][0].y >> lines[i][1].x >> lines[i][1].y;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (is_crossed(i, j)) unn(i, j);
		}
	}
	unordered_set<int> us;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int a = find(i);
		if (us.find(a) == us.end()) {
			us.insert(a);
			mx = max(mx, weight[a]);
		}
	}
	cout << us.size() << "\n" << mx;
}