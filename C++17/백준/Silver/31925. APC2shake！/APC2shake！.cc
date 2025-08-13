#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	vector<pair<int,string>> hu;
	while (n--) {
		string name, j, i;int s, a; cin >> name >> j >> i >> s >> a;
		if (j.compare("hewhak") && i.compare("winner") && (s > 3 || s == -1))
			hu.push_back({ a,name });
	}

	sort(hu.begin(), hu.end());
	vector<string> name;

	int ans = min((int)hu.size(), 10);
	cout << ans << "\n";


	for (int i = 0; i < ans; i++)
		name.push_back(hu[i].second);

	sort(name.begin(), name.end());

	for (auto a : name)cout << a << "\n";

	return 0;
}