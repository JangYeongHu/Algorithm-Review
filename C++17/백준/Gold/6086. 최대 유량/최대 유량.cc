#include <bits/stdc++.h>
using namespace std;

int capacity[52][52];
int parent[52];
int N = 52;

int make_idx(char x) {
    if (x <= 'Z') return x - 'A';
    return x - 'a' + 26;
}

bool bfs(int s, int t) {
    fill(parent, parent + N, -1);
    queue<int> q;
    q.push(s);
    parent[s] = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < N; v++) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int max_flow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }
        flow += path_flow;
    }
    return flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        int aa = make_idx(a), bb = make_idx(b);
        capacity[aa][bb] += c;
        capacity[bb][aa] += c;
    }

    cout << max_flow(0, 25);
    return 0;
}