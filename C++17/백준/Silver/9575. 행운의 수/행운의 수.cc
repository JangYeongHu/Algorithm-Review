#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
	while (x) {
		if (x % 10 != 5 && x % 10 != 8) return 0;
		x /= 10;
	}

	return 1;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> A(n);
		for (int i = 0; i < n; i++) cin >> A[i];

		int m; cin >> m;
		vector<int> B(m);
		for (int i = 0; i < m; i++) cin >> B[i];

		int k; cin >> k;
		vector<int> C(k);
		for (int i = 0; i < k; i++) cin >> C[i];
		unordered_set<int> hs;
		for (int a : A)
			for (int b : B)
				for (int c : C)
					if (check(a + b + c)) hs.insert(a + b + c);
		cout << hs.size() << "\n";
	}
}