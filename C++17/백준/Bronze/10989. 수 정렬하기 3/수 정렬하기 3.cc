#include <iostream>
using namespace std;
int a[10001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b;
		a[b] += 1;
	}
	
	for (int i = 1; i <= 10000; i++) 
		while (a[i]-- > 0) cout << i << "\n";

	return 0;
}