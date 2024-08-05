#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> um;
long long recur(long long n, int p, int q) {
	if (um.count(n)) return um[n];
	um[n] = recur(n / p, p, q) + recur(n / q, p, q);
	return um[n];
}

int main() {
	long long n;
	int p, q;
	cin >> n >> p >> q;
	um[0] = 1;
	recur(n, p, q);
	cout << um[n];
	return 0;
}