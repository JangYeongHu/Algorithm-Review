#include <bits/stdc++.h>
using namespace std;
int arr[20];
int n,s;
int BackTrancking(int k, int num) {
	if (k == n)
		return num==s;
	return BackTrancking(k + 1, num) + BackTrancking(k + 1, num + arr[k]);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	int ans = BackTrancking(0, 0);

	if (!s) ans--;

	cout << ans;
	return 0;
}