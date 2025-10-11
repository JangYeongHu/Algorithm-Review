#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		int now = 2;
		while (1) {
			if (i - now * now < 0) break;
			arr[i] = min(arr[i], arr[i - now * now]+1);
			now++;
		}
	}
	cout << arr[n];
}