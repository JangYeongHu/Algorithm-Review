#include <bits/stdc++.h>
using namespace std;
int arr[1'000'001],x[1'000'001];

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n,sz = 0;
	cin >> n;
	stack<int> st,res;
	for (int i = 0; i < n; i++) x[i + 1] = 1 << 30;
	for (int i = 0; i < n; i++) {
		int start = 0, end = n, mid,mn = end;
		cin >> arr[i+1];
		while (start <= end) {
			mid = (start + end) / 2;
			if (x[mid] >= arr[i + 1]) {
				end = mid - 1;
				if (mn > mid) mn = mid;
			}
			else {
				start = mid + 1;
			}
		}
		x[mn] = arr[i + 1];
		sz = max(sz, mn);
		st.push(mn);
	}
	int idx = st.size();
	while (idx>0) {
		if (st.top() == sz) {
			res.push(arr[idx]);
			sz--;
		}
		st.pop();
		idx--;
	}
	cout << res.size() << "\n";
	while (!res.empty()) {
		cout << res.top() << " ";
		res.pop();
	}
}