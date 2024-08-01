#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int k;
	int arr[50];
	cin >> k;
	for (int j = 1; j <= k; j++) {
		int n,a,mx = 0;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		for (int i = 1; i < n; i++)
			if (arr[i] - arr[i - 1] > mx) mx = arr[i] - arr[i - 1];
		cout << "Class " << j << "\nMax " << arr[n - 1] << ", Min " << arr[0] << ", Largest gap " << mx << "\n";
	}
	return 0;
}