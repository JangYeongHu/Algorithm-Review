#include <bits/stdc++.h>
using namespace std;
vector<int> mL,mR;
vector<char> ord;
int main() {
	int n; cin >> n;
	int mx = 0;
	char mxd;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		char c; cin >> c;
		if (mx < a) {
			mx = a;
			mxd = c;
		}
		if (c == 'L') { mL.push_back(a); ord.push_back('L'); }
		else { mR.push_back(a); ord.push_back('R');}
	}

	sort(mL.begin(), mL.end());
	sort(mR.begin(), mR.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ord[i] != mxd) continue;
		int idxl = 0, idxr = 0;
		vector<int> temp(n,0);
		temp[i] = mx;
		for (int j = 0; j < i; j++) {
			if (ord[j] == 'L') continue;
			temp[j] = mR[idxr++];
		}
		for (int j = n-1; j > i; j--) {
			if (ord[j] == 'R') continue;
			temp[j] = mL[idxl++];
		}
		int cnt = 1;
		for (int j = 0; j < i; j++) {
			if (ord[j] == 'R') continue;
			if (j == 0) {
				temp[j] = mL[idxl++];
				cnt++;
			}
			else {
				while (idxl < mL.size() && temp[j-1] > mL[idxl]) idxl++;
				if (idxl == mL.size()) break;
				if (mL[idxl] == mx) break;
				temp[j] = mL[idxl++];
				cnt++;
			}
		}
		for (int j = n-1; j > i; j--) {
			if (ord[j] == 'L') continue;
			if (j == n - 1) {
				temp[j] = mR[idxr++];
				cnt++;
			}
			else {
				while (idxr < mR.size() && temp[j+1] > mR[idxr]) idxr++;
				if (idxr == mR.size()) break;
				if (mR[idxr] == mx) break;
				temp[j] = mR[idxr++];
				cnt++;
			}
		}
		ans = max(cnt, ans);
	}
	cout << ans;

	return 0;
}