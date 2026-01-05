#include <bits/stdc++.h>
using namespace std;

int m, cityDist = 1 << 30;
vector<pair<int, int>> house, chicken;
vector<int> houseDis;
vector<bool> vis;

void backtrack(int idx, int cnt) {
    if (cnt == m) {
        int total = 0;
        for (int dist : houseDis) {
            total += dist;
        }
        cityDist = min(cityDist, total);
        return;
    }
    
    if (idx == chicken.size()) return;
    
    vis[idx] = true;
    
    vector<int> backup = houseDis;
    
    auto [x,y] = chicken[idx];

    for (int i = 0; i < house.size(); i++) {
        int dist = abs(x - house[i].first) + abs(y - house[i].second);
        houseDis[i] = min(houseDis[i], dist);
    }
    
    backtrack(idx + 1, cnt + 1);
    
    vis[idx] = false;
    houseDis = backup;

    backtrack(idx + 1, cnt);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (val == 1) house.push_back({j, i});
            else if (val == 2) chicken.push_back({j, i});
        }
    }
    
    houseDis.assign(house.size(), 1 << 30);
    vis.assign(chicken.size(), false);
    
    backtrack(0, 0);
    
    cout << cityDist;
    
    return 0;
}