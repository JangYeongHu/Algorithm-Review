#include <algorithm>
#include <iostream>
int arr[1000000];
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	return 0;
}