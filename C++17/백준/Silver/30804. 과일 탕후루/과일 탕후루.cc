#include <bits/stdc++.h>
using namespace std;
int fruit[11];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, cnt = 0,vri = 0,res = 0;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (fruit[a] == 0) vri++;
		fruit[a]++;
		q.push(a);
		while (vri > 2) {
			int t = q.front();
			q.pop();
			fruit[t]--;
			if (fruit[t] == 0)vri--;
		}
		res = max(res,(int) q.size());
	}
	cout << res;
}