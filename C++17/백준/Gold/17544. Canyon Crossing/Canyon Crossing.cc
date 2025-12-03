#include <bits/stdc++.h>
using namespace std;

int mp[1000][1000];
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
int r,c,k;
int bfs(int a) {
    vector<vector<int>> vis(r,vector<int>(c,0));
    deque<pair<int,int>> dq;
    for (int i = 0; i < c; i++)
    {
        if(mp[0][i] >= a) {
            dq.push_front({0,i});
            vis[0][i] = 1;
        } else {
            dq.push_back({0,i});
            vis[0][i] = 2;
        }
    }

    while(!dq.empty()) {
        auto [y,x] = dq.front(); dq.pop_front();
        //cout << x << " " << y << " " << vis[y][x] << "\n";
        for(int i = 0 ; i < 4; i++) {
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx < 0 || tx >= c || ty < 0 || ty >= r) continue;
            if(vis[ty][tx] != 0) continue;
            if(mp[ty][tx] >= a) {
                dq.push_front({ty,tx});
                vis[ty][tx] = vis[y][x];
            } else {
                dq.push_back({ty,tx});
                vis[ty][tx] = vis[y][x]+1;
            }

        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < c; i++)
    {
        if(vis[r-1][i] && vis[r-1][i] < ans)
            ans = vis[r-1][i];
    }

    return ans-1;
}

int main() {
    cin >> r >> c >> k;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> mp[i][j];

    int start = 0,end = 1000000000, mid;
    int ans = 0;
    while(start <= end) {
        mid = (start+end)/2;
        if(bfs(mid) <= k) {
            ans = max(mid,ans);
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    cout << ans;
}