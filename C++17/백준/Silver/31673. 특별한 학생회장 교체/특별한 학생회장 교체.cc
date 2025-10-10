#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long n, m; cin >> n >> m;
	vector<int> v(n);
	long long sum = 0,s=0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end(),greater<int>());
	int idx = 0;
	while (sum > s * 2) s += v[idx++];
	cout << m / (idx+1);
}