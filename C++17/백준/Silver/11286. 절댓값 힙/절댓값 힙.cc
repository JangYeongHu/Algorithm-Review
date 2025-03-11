#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
        if(abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int main() {
	priority_queue<int, vector<int>, cmp> pq;
	int t;
	cin >> t;
	while (t-- > 0) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n"; pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
}