#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int res = 1;
	for (int i = n - 1; i > 0; i--) {
		int t = i,now = i;
		while (now < n) now += --t;
		if (now == n) res++;
	}
	cout << res;
	return 0;
}