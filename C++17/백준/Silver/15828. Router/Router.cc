#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	queue<int> q;
	while (1) {
		int t; cin >> t;
		if (t == -1) break;
		if (t == 0) q.pop();
		else if (q.size() >= n) continue;
		else q.push(t);
	}

	if (q.empty()) cout << "empty";
	else {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
	}

	return 0;
}