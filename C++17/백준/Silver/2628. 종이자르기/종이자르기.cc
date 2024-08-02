#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int w, h, k;
	cin >> w >> h >> k;
	vector<int> horiz = { 0,h }, verti = {0,w};
	while (k-- > 0) {
		int a, b;
		cin >> a >> b;
		if (a) verti.push_back(b);
		else horiz.push_back(b);
	}
	sort(verti.begin(), verti.end());
	sort(horiz.begin(), horiz.end());
	int hmx = 0, vmx = 0;
	for (int i = 1; i < verti.size(); i++)
		if (vmx < verti[i] - verti[i - 1]) vmx = verti[i] - verti[i - 1];
	for (int i = 1; i < horiz.size(); i++)
		if (hmx < horiz[i] - horiz[i - 1]) hmx = horiz[i] - horiz[i - 1];
	cout << hmx * vmx;
	return 0;
}