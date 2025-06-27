#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
vector<string> tle;

int parent[200 * 200 * 8];
int height[200 * 200 * 8];
int r, c;
int find(int x) {
	while (parent[x] != x) x = parent[x];
	return x;
}

int make_one(int x, int y, int z) {
	return(z * (c * r) + y * c + x);
}

void union_bulk(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (height[a] > height[b]) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
	if (height[a] == height[b]) height[b]++;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		tle.push_back(s);
	}
	int ans = 0;

	for (int i = 0; i < r * c * 8; i++) {
		parent[i] = i;
		height[i] = 0;
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (tle[j][i] == 'O') {
				union_bulk(make_one(i, j, 0), make_one(i, j, 4));
				union_bulk(make_one(i, j, 1), make_one(i, j, 5));
				union_bulk(make_one(i, j, 2), make_one(i, j, 6));
				union_bulk(make_one(i, j, 3), make_one(i, j, 7));
			} else if(tle[j][i] == 'I') {
				union_bulk(make_one(i, j, 0), make_one(i, j, 1));
				union_bulk(make_one(i, j, 2), make_one(i, j, 3));
				union_bulk(make_one(i, j, 4), make_one(i, j, 5));
				union_bulk(make_one(i, j, 6), make_one(i, j, 7));
			} else {
				union_bulk(make_one(i, j, 0), make_one(i, j, 3));
				union_bulk(make_one(i, j, 1), make_one(i, j, 2));
				union_bulk(make_one(i, j, 4), make_one(i, j, 7));
				union_bulk(make_one(i, j, 6), make_one(i, j, 5));
			}
			if (i != c - 1) {
				union_bulk(make_one(i, j, 2), make_one(i+1, j,  1));
				union_bulk(make_one(i, j, 3), make_one(i + 1, j, 0));
				union_bulk(make_one(i, j, 6), make_one(i + 1, j, 5));
				union_bulk(make_one(i, j, 7), make_one(i + 1, j, 4));
			}
			if (j != r - 1) {
				union_bulk(make_one(i, j, 1), make_one(i, j+1, 0));
				union_bulk(make_one(i, j, 2), make_one(i, j + 1, 3));
				union_bulk(make_one(i, j, 5), make_one(i, j + 1, 4));
				union_bulk(make_one(i, j, 6), make_one(i, j + 1, 7));
			}
		}
	}

	unordered_set<int> st;

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			for (int k = 0; k < 8; k++)
				if (st.find(find(make_one(i, j, k))) == st.end())
					st.insert(find(make_one(i, j, k)));

	cout << st.size();

	return 0;
}