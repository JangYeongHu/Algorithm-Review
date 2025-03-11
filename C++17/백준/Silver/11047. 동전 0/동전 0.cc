#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k,res = 0;
	int a[10];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		res += k / a[i];
		k %= a[i];
	}
	cout << res;
}