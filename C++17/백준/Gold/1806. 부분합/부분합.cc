#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	int start = 0, end = 1,len = 1<<28;
	while (start != end && end <= n) {
		if (arr[end] - arr[start] >= s) { len = min(len, end - start); start++; }
		else end++;
	}
	if (len == 1 << 28) cout << 0;
	else cout << len;
}