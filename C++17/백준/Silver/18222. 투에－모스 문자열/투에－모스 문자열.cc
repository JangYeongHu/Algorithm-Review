#include <bits/stdc++.h>
using namespace std;

bool recurse(long long k,long long x) {
	if (k == 1) return 0;
	long long t = x / 2;
	if (k > t) return !recurse(k - t, x / 2);
	return recurse(k, x / 2);
}

int main() {
	long long k; cin >> k;
	long long x = 1;
	while (x < k) x <<= 1;
	cout << recurse(k, x);
}