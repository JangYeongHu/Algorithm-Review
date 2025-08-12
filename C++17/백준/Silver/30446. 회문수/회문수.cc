#include <iostream>
using namespace std;
int arra[13];
int arrb[13];
long long n;
bool take = 0;
bool check() {
	int ind = 0;
	long long num = 0;
	while (arra[++ind] == 0);
	if (take == 0) {
		for (int i = ind; i < 13 - ind; i++) {
			num = num * 10 + arra[i];
		}
		//cout << n << " " << num << "\n";
		if (num <= n) return 1;
		return 0;
	}
	else {
		for (int i = ind; i < 12 - ind; i++) {
			num = num * 10 + arrb[i];
		}
		//cout << n << " " << num << "\n";
		if (num <= n) return 1;
		return 0;
	}
}

int main() {
	arra[6] = 1;
	arrb[6] = arrb[5] = 1;
	int cnt = 0;
	cin >> n;
	int mx_h = 6;
	int mn_j = 5;
	int targeta = 6;
	int target = 5;
	while (check()) {
		if (take == 0) {
			while (arra[targeta] == 9) { arra[targeta] = arra[12 - targeta] = 0; targeta++; }
			arra[targeta]++;
			if (targeta != 6) { arra[12 - targeta]++; }
			cnt++;
			if (mx_h < targeta) { take = 1; mx_h = targeta; }
			targeta = 6;
		}
		else {
			while (arrb[target] == 9) { arrb[target] = arrb[11 - target] = 0; target--; }
			arrb[target]++; arrb[11 - target]++;
			cnt++;
			if (mn_j > target) { take = 0; mn_j = target; }
			target = 5;
		}
	}
	cout << cnt;
}