#include <iostream>
#include <cmath>
using namespace std;

int a[2][2] = { {0,1}, {2,3} };

long long Z(int n, int y, int x) {
	if (n == 1) return a[y][x];
	return 1LL * pow(4,n-1)*a[y/pow(2,n-1) >= 1][x / pow(2, n-1) >= 1] + Z(n-1, y % (int)pow(2, n - 1), x % (int)pow(2, n - 1));
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	cout << Z(n, r, c);
	return 0;
}