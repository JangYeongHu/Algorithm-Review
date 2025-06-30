#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<string> sukgo;
int parent[200*200*8];
int height[200 * 200 * 8];
int r, c;

int find(int x) {
	while (parent[x] != x) { x = parent[x];}
	return x;
}

int make_idx(int x, int y, int z) {
	return z * r * c + y * c + x;
}

void unn(int a,int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (height[a] > height[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
	if (height[a] == height[b]) {
		height[b]++;
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		sukgo.push_back(s);
	}

	for (int i = 0; i < r * c * 8; i++) {
		height[i] = 0;
		parent[i] = i;
	}

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (sukgo[y][x] == 'H') {
				unn(make_idx(x, y, 0), make_idx(x, y, 3));
				unn(make_idx(x, y, 1), make_idx(x, y, 2));
				unn(make_idx(x, y, 4), make_idx(x, y, 7));
				unn(make_idx(x, y, 6), make_idx(x, y, 5));
			}
			if (sukgo[y][x] == 'I') {
				unn(make_idx(x, y, 0), make_idx(x, y, 1));
				unn(make_idx(x, y, 2), make_idx(x, y, 3));
				unn(make_idx(x, y, 4), make_idx(x, y, 5));
				unn(make_idx(x, y, 6), make_idx(x, y, 7));
			}
			if (sukgo[y][x] == 'O') {
				unn(make_idx(x, y, 0), make_idx(x, y, 4));
				unn(make_idx(x, y, 1), make_idx(x, y, 5));
				unn(make_idx(x, y, 2), make_idx(x, y, 6));
				unn(make_idx(x, y, 3), make_idx(x, y, 7));
			}
			if (x != c - 1) {
				unn(make_idx(x, y, 2), make_idx(x + 1, y, 1));
				unn(make_idx(x, y, 3), make_idx(x + 1, y, 0));
				unn(make_idx(x, y, 6), make_idx(x + 1, y, 5));
				unn(make_idx(x, y, 7), make_idx(x + 1, y, 4));
			}
			if (y != r - 1) {
				unn(make_idx(x, y, 1), make_idx(x, y+1, 0));
				unn(make_idx(x, y, 2), make_idx(x, y+1, 3));
				unn(make_idx(x, y, 6), make_idx(x, y+1, 7));
				unn(make_idx(x, y, 5), make_idx(x, y+1, 4));
			}
		}
	}

	unordered_set<int> ans;
	for (int i = 0; i < r * c * 8; i++) {
		if (ans.find(find(i)) != ans.end()) continue;
		ans.insert(find(i));
	}

	cout << ans.size();

	return 0;
}