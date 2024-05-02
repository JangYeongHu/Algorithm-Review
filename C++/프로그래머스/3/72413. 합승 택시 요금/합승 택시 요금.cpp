#include <string>
#include <vector>
#include <queue>

using namespace std;

int dijk(vector<pair<int,int>> road[], int a, int b, int c, int e, int n) {
    priority_queue<pair<int, int>> pq;
    int vis[201];
    fill_n(vis, 201, 1 << 29);
    vis[a] = 0;
    pq.push({ 0,a });
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int d = t.second, v = t.first;
        for (auto iter = road[d].begin(); iter != road[d].end(); iter++) {
            if (vis[(*iter).first] <= (*iter).second - v) continue;
            vis[(*iter).first] = (*iter).second - v;
            pq.push({ v - (*iter).second,(*iter).first});
        }
    }
    return vis[b] + vis[c] + vis[e];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<pair<int,int>> road[201];
    for (int i = 1; i <= 200; i++) road[i].resize(0);
    int answer = 1 << 30;
    for (int i = 0; i < fares.size(); i++) {
        int c = fares[i][0], d = fares[i][1], f = fares[i][2];
        road[c].push_back({ d,f });
        road[d].push_back({ c,f });
    }
    for (int i = 1; i <= n; i++) answer = min(answer, dijk(road, i, s, a, b, n));
    return answer;
}