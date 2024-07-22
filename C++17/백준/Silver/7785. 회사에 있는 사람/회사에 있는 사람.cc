#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<string, greater<string>> company;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s, inout;
		cin >> s >> inout;
		if (!inout.compare("enter")) company.insert(s);
		else company.erase(s);
	}
	for (auto iter = company.begin(); iter != company.end(); iter++) cout << *iter << "\n";
	return 0;
}