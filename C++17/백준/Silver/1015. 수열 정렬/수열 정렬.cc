#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int arr[1000];
	int cpy[1000];
	int ans[1000];
	for (int i = 0; i < n; i++) { cin >> arr[i]; ans[i] = -1; }
	copy(arr,arr+n,cpy);
	sort(arr, arr+n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cpy[j] == arr[i] && ans[j] == -1) {
				ans[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) cout << ans[i] << " ";

	return 0;
}