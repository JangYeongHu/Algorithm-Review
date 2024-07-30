#include <iostream>
using namespace std;
bool arr[101][101];

int main(){
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int x = a; x < c; x++)
			for (int y = b; y < d; y++)
				arr[y][x] = 1;
	}
	int cnt = 0;
	for (int i = 1; i < 101; i++)
		for (int j = 1; j < 101; j++)
			if (arr[i][j]) cnt++;
	cout << cnt;
	return 0;
}