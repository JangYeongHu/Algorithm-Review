#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	if(n%2)n--;
	cout << floor(n*log10(2));
}