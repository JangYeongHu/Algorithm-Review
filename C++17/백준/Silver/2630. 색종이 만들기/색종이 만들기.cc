#include <iostream>
#include <cmath>

using namespace std;

bool paper[128][128];

int blue[2];

int con(int x, int y,int n, bool is_blue) {
	if (n == 1)
		if (paper[y][x] == is_blue)return 1;
		else return 0;
	int res = 0;
	for (int i = 0; i < 4; i++)
		res += con(x + (n / 2 * (i % 2)), y + (n / 2 * (i / 2)), n / 2,is_blue);

	if (res == 4) return 1;
	blue[is_blue] += res;
	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	blue[0] += con(0, 0, n, 0);
	blue[1] += con(0, 0, n, 1);

	cout << blue[0] << "\n" << blue[1];
	return 0;
}