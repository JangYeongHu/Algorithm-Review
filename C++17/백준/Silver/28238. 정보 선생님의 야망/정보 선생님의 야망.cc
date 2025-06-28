#include <bits/stdc++.h>
using namespace std;
bool arr[1000'000][5];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	int mx = 0,a = 0,b = 1;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++) {
			int s = 0;
			for (int k = 0; k < n; k++)
				if (arr[k][i] && arr[k][j]) s++;
			if (s > mx) {
				mx = s; a = i; b = j;
			}
		}

	cout << mx << "\n";
	for (int i = 0; i < 5; i++)
		if (a == i || b == i) cout << "1 ";
		else cout << "0 ";

	return 0;
}