#include <string>
#include <vector>

using namespace std;
int arr[1000][1000];
int dx[] = { 0,1,-1 }, dy[] = { 1,0,-1 };

vector<int> solution(int n) {
    int x = 0, y = 0,ind = 0;
    arr[0][0] = 1;
    while (1) {
        if (arr[y][x] == (n + 1) * n / 2) break;
        int tx = x + dx[ind], ty = y + dy[ind];
        if (tx < 0 || tx >= n || ty < 0 || ty >= n) {
            ind = (ind + 1) % 3;
            continue;
        }
        if (arr[ty][tx]) {
            ind = (ind + 1) % 3;
            continue;
        }
        arr[ty][tx] = arr[y][x] + 1;
        x = tx; y = ty;
    }
    vector<int> answer;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) answer.push_back(arr[i][j]);
    return answer;
}