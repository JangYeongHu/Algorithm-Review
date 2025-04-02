#include <bits/stdc++.h>
using namespace std;

long long cnt(long long x) {
	long long now = 2;
	long long res = 0;
	for(int i = 0; i < 60; i++) {
		res += (x / now) * (now / 2) + (x % now - (now/2) > 0 ? x%now - (now/2) : 0);
		now *= 2;
	}
	return res;
}

int main() {
	long long a, b;
	cin >> a >> b;
	cout << cnt(b + 1) - cnt(a);
}