#include <iostream>
using namespace std;
int main(){
	long long a = 0, b = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t = a + b; a = b; b = t;
	}
	cout << (a + b) * 2;
	return 0;
}