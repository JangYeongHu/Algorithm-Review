#include <iostream>
using namespace std;
long long arr[1000001];
int main() {
	int T,n;
	cin >>T;
	arr[1] = 1; arr[2] = 2; arr[3] = 4;
	for (int i = 4; i < 1000001; i++)
		arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3])%1000000009;
	while (T-- > 0) {
		cin >> n;
		cout << arr[n] << "\n";
	}
	return 0;
}