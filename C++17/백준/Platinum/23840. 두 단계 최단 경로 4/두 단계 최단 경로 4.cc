#include <bits/stdc++.h>
using namespace std;
#define INF 1LL<<60
int need_node[20];
vector <pair<long long, long long>> node[100001];
long long node_map[20][20];
long long tsp_map[20][1 << 20];
int n, m, p;
long long dis[100001], dis_x[100001], dis_z[100001];
int x, z;

long long tsp(int now, int is_visited) {
    if (tsp_map[now][is_visited]) return tsp_map[now][is_visited];
    if (is_visited == ((1 << p)- 1)) return dis_z[need_node[now]];
    long long res = INF;
    for (int i = 0; i < p; i++) {
        if (is_visited & (1<<i) || node_map[i][now] == INF) continue;
        res = min(res,tsp(i, is_visited | (1 << i))+node_map[now][i]);
    }
    return tsp_map[now][is_visited] = res;
}

void dijk(int x) {
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[x] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({ 0,x });
    while (!pq.empty()) {
        auto [d, no] = pq.top();
        pq.pop();
        d *= -1;
        if (dis[no] < d) continue;
        for (auto t : node[no]) {
            if (dis[t.first] > dis[no] + t.second) {
                dis[t.first] = dis[no] + t.second;
                pq.push({ -dis[t.first] , t.first });
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({ v,w });
        node[v].push_back({ u,w });
    }
    cin >> x >> z >> p;
    for (int i = 0; i < p; i++) {
        cin >> need_node[i];
        for (int j = 0; j < p; j++) node_map[i][j] = INF;
    }

    for (int i = 0; i < p; i++) {
        dijk(need_node[i]);
        for (int j = 0; j < p; j++) node_map[i][j] = node_map[j][i] = dis[need_node[j]];
    }

    dijk(x);
    for (int i = 1; i <= n; i++) dis_x[i] = dis[i];
    dijk(z);
    for (int i = 1; i <= n; i++) dis_z[i] = dis[i];

    long long ans = INF;

    for (int i = 0; i < p; i++) {
        int a = need_node[i];
        long long t = tsp(i, 1 << i);
        ans = min(ans, dis_x[a] + t);
    }
    if (ans >= INF) cout << -1;
    else cout << ans;
}