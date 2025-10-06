#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n,m; cin >> n >> m;
	vector<vector<int>> arr;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			int t; cin >> t;
			v.push_back(t);
		}
		arr.push_back(v);
	}

	sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
		return count(a.begin(), a.end(), 1) > count(b.begin(), b.end(), 1);
		});

	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[j][i] == 1 && arr[j - 1][i] == 0) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}