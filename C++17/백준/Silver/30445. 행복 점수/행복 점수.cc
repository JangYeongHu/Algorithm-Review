#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;
char sad[] = { 'S','A','D' }, happy[] = { 'H','A','P','Y' };
int main() {
	string s;
	getline(cin, s);
	double pg = 0, ph = 0;
	for (char c : s) {
		for (char ch: sad) pg += (c == ch);
		for (char ch: happy) ph += (c == ch);
	}
	double res;
	if (pg == 0 && ph == 0) res = 5000;
	else res = round(ph * 10000 / (ph + pg));
	printf("%.2lf", res / 100);
	return 0;
}