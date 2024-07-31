#include <iostream>
using namespace std;
int main(){
	int n,res=0;
	cin >> n;
	while (res * res <= n) res++;
	cout << res-1;
	return 0;
}