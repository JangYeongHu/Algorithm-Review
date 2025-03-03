#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int num[1001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	for (int i = 1; i < n; i++) num[i] += num[i - 1];
	int res = 0;
	for (int i = 0; i < n; i++) res += num[i];
	cout << res;
	return 0;
}