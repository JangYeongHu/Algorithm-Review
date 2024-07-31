#include <iostream>
using namespace std;
bool w[1001];
int main(){
	int n;
	cin >> n;
	w[2] = 1;
	for (int i = 4; i <= 1000; i++)
		if (w[i - 3] == 0 && w[i - 1] == 0) w[i] = 1;
	if (w[n]) cout << "SK";
	else cout << "CY";
	return 0;
}