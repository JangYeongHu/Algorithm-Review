#include <iostream>
using namespace std;
int main() {
	long long a, b;
	cin >> a >> b;
	long long c = a, d = b;
	while (d != 0) {
		long long t = c % d; c = d; d = t;
	}
	cout << a / c * b;
	return 0;
}