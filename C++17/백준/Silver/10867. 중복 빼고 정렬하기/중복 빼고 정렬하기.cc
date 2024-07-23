#include <iostream>
#include <set>
using namespace std;
int main() {
	set<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		s.insert(t);
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) cout << *iter << " ";
	return 0;
}