#include <iostream>
using namespace std;
int arr[20],res[20];
int main(){
	int a, b,m;
	cin >> a >> b >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	int n = 1,number = 0;
	for (int i = m - 1; i >= 0; i--) {
		number += n * arr[i];
		n *= a;
	}
	int ind = 0;
	do {
		res[ind++] = number % b;
		number /= b;
	} while (number);
	for (int i = ind-1; i >= 0; i--) cout << res[i] << " ";
	return 0;
}