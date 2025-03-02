#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<string> d, b;
vector<string> db;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		d.insert(t);
	}
	for (int i = 0; i < m; i++) {
		string t;
		cin >> t;
		b.insert(t);
	}
	if (n > m) {
		for (string s : b)
			if (d.find(s) != d.end()) db.push_back(s);
	} else {
		for (string s : d)
			if (b.find(s) != b.end()) db.push_back(s);
	}
	sort(db.begin(), db.end());
	cout << db.size() << "\n";
	for (string s : db)
		cout << s << "\n";
	return 0;
}