#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[8];
void res(int now, int num) {
	if (now == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = num; i <= now + n - m+1; i++) {
		arr[now] = i;
		res(now + 1, i+1);
	}
}

int main() {
	cin >> n >> m;
	res(0, 1);
}