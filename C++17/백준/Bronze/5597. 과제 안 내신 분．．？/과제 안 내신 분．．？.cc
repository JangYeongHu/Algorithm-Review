#include <bits/stdc++.h>
using namespace std;

bool arr[31];
int main() {
	for(int i = 0; i < 28; i++) {
		int t; cin >> t;
		arr[t] = 1;
	}
	for(int i = 1; i <= 30; i++) {
		if(arr[i] == 0) {
			cout << i << "\n";
		}
	}
}