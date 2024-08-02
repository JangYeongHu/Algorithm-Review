#include <iostream>
using namespace std;
int main(){
	int n, m,j;
	cin >> n >> m >> j;
	int left = 1, right = m,res = 0;
	for (int i = 0; i < j; i++) {
		int a;
		cin >> a;
		if (a < left) {
			res += left - a;
			left = a;
			right = left + m-1;
		}
		if (a > right) {
			res += a-right;
			right = a;
			left = right - m + 1;
		}
	}
	cout << res;
	return 0;
}