#include <iostream>
using namespace std;
int arr[100010];
int main() {
	int n;
	cin >> n;
	arr[2] = 1; arr[5] = 1;
	for (int i = 2; i < 100001; i++) {
		if (arr[i]) {
			if (!arr[i + 2]) arr[i + 2] = arr[i] + 1;
			if (!arr[i + 5]) arr[i + 5] = arr[i] + 1;
		}
	}
	if (arr[n]) cout << arr[n];
	else cout << -1;
	return 0;
}