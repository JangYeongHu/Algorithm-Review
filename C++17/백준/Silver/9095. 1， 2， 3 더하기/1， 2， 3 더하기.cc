#include <iostream>
using namespace std;
int num[12];
int main() {
	num[0] = 1;
	num[1] = 1;
	num[2] = 2;
	for (int i = 3; i < 12; i++)num[i]=num[i-1]+num[i - 2]+num[i - 3];
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		cout << num[n]<<"\n";
	}
	return 0;
}