#include <bits/stdc++.h>
using namespace std;
int arr[100];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n == 1 || n == 2) {
		if (n == 2 && arr[0] == arr[1]) cout << arr[0];
		else cout << 'A';
		return 0;
	}

	for (int a = -200; a <= 200; a++) {
		int b = arr[1] - arr[0] * a;
		bool c = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i-1] * a + b != arr[i]) {
				c = 1; break;
			}
		}

		if (!c) {
			cout << arr[n - 1] * a + b;
			return 0;
		}
	}
	cout << 'B';
}