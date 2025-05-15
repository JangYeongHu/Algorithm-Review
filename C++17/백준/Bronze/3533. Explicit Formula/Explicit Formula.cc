#include <bits/stdc++.h>
using namespace std;
bool a[10];
int main() {
	bool res = 0;
	for (int i = 0; i < 10; i++) cin >> a[i];
	for (int i = 0; i < 9; i++)
		for (int j = i+1; j < 10; j++)
			res ^= a[i] || a[j];

	for (int i = 0; i < 8; i++)
		for (int j = i+1; j < 9; j++)
			for (int k = j+1; k < 10; k++)
				res ^= a[i] || a[j] || a[k];
	cout << res;
	return 0;
}