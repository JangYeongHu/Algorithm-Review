#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c,res = 1;
	cin >> a >> b >> c;
	while (b) {
		if (b % 2)res = (1LL * res*a) % c;
		a = (1LL * a * a) % c;
		b /= 2;
	}
	cout << res;
}