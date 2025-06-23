#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[100001];

ll get_from_mid(int s,int m, int e) {
	int t1 = m,t2 = m;
	 ll res = 0,mn = 0;
	while (1) {
		if (t1 == s) t2++;
		else if (t2 == e) t1--;
		else if (arr[t1 - 1] > arr[t2 + 1]) t1--;
		else t2++;
		if (t1 < s || t2 > e) break;
		mn = min(arr[t1], arr[t2]);
		while (1) {
			if (t1 == s) break;
			if (arr[t1 - 1] < mn) break;
			t1--;
		}
		while (1) {
			if (t2 == e) break;
			if (arr[t2 + 1] < mn) break;
			t2++;
		}
		res = max(res, (t2 - t1 + 1) * mn);
	}
	return res;
}

ll get(int s, int e) {
	if (s == e) return arr[s];
	int m = (s + e) / 2;
	ll r1 = get_from_mid(s,m,e);
	return max(max(get(s, m), get(m + 1, e)), r1);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		cout << get(0,n-1) << "\n";
	}
	return 0;
}