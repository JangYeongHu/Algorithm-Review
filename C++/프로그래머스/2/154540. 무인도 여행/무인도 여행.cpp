#include <string>
#include <vector>
#include <queue>
#include <algorithm>
int arr[100][100];
int vis[100][100];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,1,-1 };
using namespace std;

int bfs(int x, int y,int ylen,int xlen) {
    queue<pair<int, int>> q;
    int res = arr[y][x];
    q.push({ x,y });
    vis[y][x] = 1;
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = t.first + dx[i];
            int ty = t.second + dy[i];
            if (tx < 0 || tx >= xlen || ty < 0 || ty >= ylen) continue;
            if (!arr[ty][tx]) continue;
            if (vis[ty][tx]) continue;
            vis[ty][tx] = 1;
            q.push({ tx,ty }); 
            res += arr[ty][tx];
        }
    }
    return res;
}

vector<int> solution(vector<string> maps) {
    int xlen = maps[0].length();
    int ylen = maps.size();
    for(int i = 0; i < ylen; i++)
        for (int j = 0; j < xlen; j++)
            if (maps[i][j] == 'X') arr[i][j] = 0;
            else arr[i][j] = maps[i][j] - '0';
    int cnt = 0;
    vector<int> answer;
    for (int i = 0; i < ylen; i++)
        for (int j = 0; j < xlen; j++)
            if (arr[i][j] && !vis[i][j]) {
                int res = bfs(j, i,ylen,xlen);
                answer.push_back(res);
            }
    if (answer.empty()) answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}