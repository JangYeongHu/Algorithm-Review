#include <bits/stdc++.h>
using namespace std;
#define SZ 9
int board[SZ][SZ];

bool Check(int x,int y,int n) {
	    for(int i = 0; i < 9; i++)
            if(board[y][i] == n && i != x) return 0;

        for(int i = 0; i < 9; i++)
            if(board[i][x] == n && i != y) return 0;

        for(int i = 0; i < 9; i++) {
            int dx = i%3;
            int dy = i/3;
            if (board[y/3*3+dy][x/3*3+dx] == n && y/3*3+dy != y && x/3*3+dx != x) return 0;
        }
    return 1;
}

bool Sudoku(int idx) {
	if(idx==81)
		return 1;

	int x = idx%SZ, y = idx/SZ;
	if(board[y][x] != 0)
		return Sudoku(idx+1);
	
	for (int i = 1; i <= SZ; i++)
	{
		if(!Check(x,y,i)) continue;
		board[y][x] = i;
		if(Sudoku(idx+1)) return 1;
		board[y][x] = 0;
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
		{
			cin >> board[i][j];
		}
	}

	Sudoku(0);

	for (int i = 0; i < SZ; i++)
	{
		for (int j = 0; j < SZ; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
	
	return 0;
}