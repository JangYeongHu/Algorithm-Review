#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(0),ios::sync_with_stdio(0),cout.tie(0)
int main() {
	FASTIO;
	int t;
	cin >> t;
	while (t-- > 0) {
		int k,size = 0;
		cin >> k;
		priority_queue<long long> min_pq,max_pq,del_min_pq,del_max_pq;

		for (int i = 0; i < k; i++) {
			char a; long long n;
			cin >> a >> n;
			if (a == 'I') {
				min_pq.push(-n);
				max_pq.push(n);
				size++;
			}
			else if (n == 1 && size != 0) {
				del_max_pq.push(-max_pq.top());
				max_pq.pop();
				size--;
			}
			else if(size != 0){
				del_min_pq.push(-min_pq.top());
				min_pq.pop();
				size--;
			}

			while (1) {
				if (del_max_pq.empty()) break;
				if (min_pq.top() != del_max_pq.top()) break;
				del_max_pq.pop(); min_pq.pop(); }
			while (1) {
				if (del_min_pq.empty()) break;
				if (max_pq.top() != del_min_pq.top()) break;
				del_min_pq.pop(); max_pq.pop();
			}
		}

		if (size == 0) cout << "EMPTY\n";
		else cout << max_pq.top() << " " << -min_pq.top() << "\n";

	}
}