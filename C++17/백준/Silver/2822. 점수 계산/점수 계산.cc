#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> s1, pair<int, int> s2) {
	return s1.second < s2.second;
}
int main() {
	pair<int, int> s[8];
	for (int i = 0; i < 8; i++) {
		int t;
		cin >> t;
		s[i] = {t,i+1};
	}
	sort(s, s + 8, greater<pair<int,int>>());
	sort(s, s + 5, cmp);
	int res = 0;
	for (int i = 0; i < 5; i++) res += s[i].first;
	cout << res << "\n";
	for (int i = 0; i < 5; i++) cout << s[i].second << " ";
	return 0;
}