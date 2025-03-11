#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FASTIO cin.tie(0), ios::sync_with_studio(0); cout.tie(0);
int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		unordered_map<string, int> clo;
		while (n-- > 0) {
			string a, b;
			cin >> a >> b;
			if (clo.find(b) != clo.end()) clo[b] += 1;
			else clo[b] = 1;
		}
		int res = 1;
		for (auto t : clo) {
			res *= (t.second+1);
		}
		cout << res - 1 << "\n";
	}
}