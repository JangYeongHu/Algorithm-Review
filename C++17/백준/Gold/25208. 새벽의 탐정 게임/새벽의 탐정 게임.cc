#include <bits/stdc++.h>
using namespace std;

char mp[500][500];
bool vis[500][500][6];

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int dd[][6] = {
    {4,1,5,3,2,0},
    {3,0,1,2,4,5},
    {5,1,4,3,0,2},
    {1,2,3,0,4,5}
};

struct el {
    int x, y, cnt, dice;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    queue<el> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'D') {
                q.push({ j, i, 0, 0 });
                vis[i][j][0] = 1;
            }
        }

    while (!q.empty()) {
        auto [x, y, cnt, di] = q.front();
        q.pop();

        if (mp[y][x] == 'R') {
            cout << cnt << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;

            int nd = dd[i][di];
            if (vis[ty][tx][nd] == 1 ||
                mp[ty][tx] == '#' ||
                (mp[ty][tx] == 'R' && nd != 0)) continue;

            vis[ty][tx][nd] = 1;
            q.push({ tx, ty, cnt + 1, nd });
        }
    }

    cout << "-1";
    return 0;
}
