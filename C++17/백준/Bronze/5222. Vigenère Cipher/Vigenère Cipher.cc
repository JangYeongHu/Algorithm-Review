#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	while (n--) {
		string k, p; cin >> k >> p;
		cout << "Ciphertext: ";
		for (int i = 0; i < p.size(); i++) {
			int idx = i % k.size();
			int g = k[idx] - 'A';
			cout << (char)('A' + (p[i] - 'A' + g) % 26);
		}
		cout << "\n";
	}
	return 0;
}