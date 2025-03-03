#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	vector < pair<int, int>> kaigi;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		kaigi.push_back({ s,e });
	}

	sort(kaigi.begin(), kaigi.end());
	int now = 0,res = 1;
	for (int i = 1; i < n; i++) {
		if (kaigi[now].second <= kaigi[i].first) {res++; now = i; }
		else if (kaigi[now].second > kaigi[i].second) now = i;
	}
	cout << res;
	return 0;
}