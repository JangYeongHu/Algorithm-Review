#include <bits/stdc++.h>
using namespace std;
int ground[500][500];
int main() {
	int n, m, b;
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ground[i][j];

	int res = 1 << 28, hei = 256;

	for (int i = 256; i >= 0; i--) {
		int tb = b, time = 0;
		for(int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				if (ground[j][k] > i) {
					time += 2 * (ground[j][k] - i);
				}
				else {
					time +=  i - ground[j][k];
				}
				tb += (ground[j][k] - i);
			}
		if (time < res && tb >= 0) { res = time; hei = i; }
	}

	cout << res << " " << hei;

}