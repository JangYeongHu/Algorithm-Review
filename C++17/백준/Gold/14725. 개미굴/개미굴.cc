#include <bits/stdc++.h>
using namespace std;

struct Node {
	unordered_map<string, Node*> s;
};

void dfs(Node* node,int d) {
	vector<pair<string,Node*>> dic;
	for (auto iter : node->s) dic.push_back(iter);
	sort(dic.begin(), dic.end());
	for (auto iter : dic) {
		for (int i = 0; i < d; i++) cout << "--";
		cout << iter.first << "\n";
		dfs(iter.second, d + 1);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	Node root = Node();
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		Node* now_node = &root;
		while (k--) {
			string s; cin >> s;
			if (now_node->s.find(s) != now_node->s.end()) {
			}
			else {
				now_node->s.insert({ s, new Node()});
			}
			now_node = now_node->s[s];
		}
	}

	dfs(&root,0);

	return 0;
}