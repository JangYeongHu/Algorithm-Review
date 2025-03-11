#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	priority_queue<int> pq;
	int n;
	cin >> n;
	while (n-- > 0) {
		int t;
		cin >> t;
		if (t == 0) {
			if (pq.empty()) cout << "0\n";
			else { cout << pq.top() << "\n"; pq.pop(); }
		}else pq.push(t);
	}

}