#include <iostream>
int num[100001];
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) { cin >> num[i]; if (i) num[i] += num[i - 1]; }
	while (m-- > 0) {
		int i, j;
		cin >> i >> j;
		cout << num[j] - num[i-1] << "\n";
	}
	return 0;
}