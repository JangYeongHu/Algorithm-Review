#include <iostream>
#include <string>
int num = 0;
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,x;
	cin >> n;
	string a;
	while (n-- > 0) {
		string a;
		cin >> a;
		if (a[1] == 'l') num = (1 << 22) - 1;
		else if (a[1] == 'm') num = 0;
		else {
			cin >> x;
			if (a[1] == 'd') num |= 1 << x;
			else if (a[1] == 'e') num &= ~(1 << x);
			else if (a[1] == 'h') cout << ((num >> x)%2) << "\n";
			else num ^= (1 << x);
		}
	}
	return 0;
}