#include <bits/stdc++.h>
using namespace std;
struct node { char l, r; };
node nodes[26];

void preorder(char x) {
	if (x == '.') return;
	node a = nodes[x-'A'];
	cout << x;
	preorder(a.l);
	preorder(a.r);
}

void inorder(char x) {
	if (x == '.') return;
	node a = nodes[x - 'A'];
	inorder(a.l);
	cout << x;
	inorder(a.r);
}

void postorder(char x) {
	if (x == '.') return;
	node a = nodes[x - 'A'];
	postorder(a.l);
	postorder(a.r);
	cout << x;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		nodes[a - 'A'].l = b;
		nodes[a - 'A'].r = c;
	}
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}