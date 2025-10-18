#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main() {
	int a, b, c; cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int s, e; cin >> s >> e;
		for (int j = s; j < e; j++)
			arr[j]++;
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		if (arr[i] == 0) continue;
		if (arr[i] == 1) ans += a;
		if (arr[i] == 2) ans += b*2;
		if (arr[i] == 3) ans += c*3;
	}
	cout << ans;
}