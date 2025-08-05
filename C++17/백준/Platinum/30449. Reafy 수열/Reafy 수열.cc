#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	k--;
    
	vector<pair<int,int>> arr;
	arr.push_back({ 0,1 });
	arr.push_back({ 1,1 });
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j +=	1 + (~i & 1)) {
			if (gcd(i, j) == 1) arr.push_back({ j,i });
		}
	}

	nth_element(arr.begin(), arr.begin() + k, arr.end(), [](auto& a, auto& b) {
		return a.first * b.second < b.first * a.second;
		});

	cout << arr[k].first << " " << arr[k].second;
}