#include <bits/stdc++.h>
using namespace std;
int room[3];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr.begin(), arr.end());
	int ans = 0;
	for (auto [e, s] : arr) {
		int mn = -1;
		if (room[0] == 0 || s - room[0] > 0) mn = 0;
		if (k >= 2 && (room[1] == 0 || s - room[1] > 0 && s - room[mn] > s - room[1])) mn = 1;
		if (k == 3 && (room[2] == 0 || s - room[2] > 0 && s - room[mn] > s - room[2])) mn = 2;
		if (mn == -1) continue;
		room[mn] = e;
		ans++;
	}
	cout << ans;
	return 0;
}