#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tree.push_back(a);
	}

	int start = 0, end = 1000000000,mid,res = 0;
	long long cnt;
	while (start <= end) {
		mid = (start + end) / 2;
		cnt = 0;
		for (int tr : tree)
			cnt += (tr > mid ? tr - mid : 0);
		if (cnt < m)
			end = mid - 1;
		else {
			res = max(res, mid);
			start = mid + 1;
		}
	}

	cout << res;

	return 0;
}