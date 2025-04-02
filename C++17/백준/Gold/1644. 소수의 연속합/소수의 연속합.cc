#include <bits/stdc++.h>
using namespace std;
vector<int> sosu = { 2 };
vector<long long> hap = { 0,2 };
int main() {
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		int x;
		for (int num : sosu) {
			x = num;
			if (1LL * num * num > i) break;
			if (i % num == 0) break;
		}
		if (1LL * x * x > i) { sosu.push_back(i); hap.push_back(hap.back()+i); }
	}
	
	int start = 0, end = 1, len = hap.size(), ans = 0;
	while (end < len && start < end) {
		if (hap[end] - hap[start] > n) start++;
		else {
			if (hap[end] - hap[start] == n) ans++;
			end++;
		}
	}
	cout << ans;
}