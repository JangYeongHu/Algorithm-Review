#include <iostream>
using namespace std;
int arr[1000000][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i][0];
	for (int i = 0; i < m; i++) cin >> arr[i][1];
	int a = 0, b = 0;
	while (a != n && b != m) {
		if (arr[a][0] < arr[b][1]) { cout << arr[a++][0] << " "; }
		else cout << arr[b++][1] << " ";
	}
	while (a != n) cout << arr[a++][0] << " ";
	while (b != m) cout << arr[b++][1] << " ";

	return 0;
}