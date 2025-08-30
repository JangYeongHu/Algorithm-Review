#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, p; cin >> n >> p;
	int cnt = 0,now = n;
	unordered_map<int, int> um;
	um.insert({ n,0 });
	while (1) {
		now = now * n % p;
		if (um.find(now) != um.end()) {
			cout << cnt - um[now] + 1;
			break;
		}
		um.insert({ now,++cnt });
	}
}