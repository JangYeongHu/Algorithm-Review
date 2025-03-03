#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	unordered_map<string, string> ps;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		ps[a] = b;
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << ps.at(a) << "\n";
	}
	return 0;
}