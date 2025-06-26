#include <bits/stdc++.h>

int arr[10001];

using namespace std;
int n, a, b;

int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int mx = 0;
	for (int x = 0; x < a; x++) {
		for (int s = 0; s < n; s++) {
			int t = 0, res = 0;
			for (int j = 0; j < n; j++) {
				if (j == s) t += b * x;
				if (j < s && arr[j] >= t + a) {
					t += a; res++;
				}
				else if (j >= s && arr[j] >= t + a - x) {
					t += a - x; res++;
				}
			}
			mx = max(mx, res);
		}
	}
	cout << mx;
	return 0;
}