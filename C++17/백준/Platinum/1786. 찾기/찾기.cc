#include <bits/stdc++.h>
using namespace std;
int pi[1'000'000];

void get_par(string a) {
	int a_s = a.size(), idx = 1, matched = 0;
	while (idx + matched < a_s) {
		if (a[idx + matched] == a[matched]) {
			matched++;
			pi[idx + matched - 1] = matched;
		}
		else if (matched == 0) idx++;
		else {
			idx += matched - pi[matched - 1];
			matched = pi[matched - 1];
		}
	}
}

vector<int> kmp(string a, string b) {
	vector<int> res;
	int a_s = a.size(), b_s = b.size(),idx = 0,matched = 0;
	while (idx <= a_s - b_s) {
		if (matched < b_s && a[idx + matched] == b[matched]) {
			matched++;
			if (matched == b_s) res.push_back(idx);
		}
		else if (matched==0){
			idx++;
		}
		else {
			idx += matched - pi[matched - 1];
			matched = pi[matched - 1];
		}
	}
	return res;
}


int main() {
	string a,b;
	getline(cin, a);
	getline(cin, b);
	get_par(b);
	auto res = kmp(a, b);
	cout << res.size() << "\n";
	for (int a : res)  cout << a+1 << "\n";
	return 0;
}