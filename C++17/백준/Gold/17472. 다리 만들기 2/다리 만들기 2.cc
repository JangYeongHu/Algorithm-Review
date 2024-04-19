#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int arr[10][10];
typedef struct { int x, y, d, i; } element;
struct cmp {
    bool operator()(const element& e1, element& e2) { return e1.i > e2.i; }};
vector<pair<int, int>> land[8];
priority_queue<element,vector<element>,cmp> pq;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int parent[8],root[8];
int n, m;
void landbfs(int ind, int x, int y) {
    queue<pair<int, int>> q;
    arr[y][x] = ind;
    q.push({ x,y });
    land[ind].push_back({ x,y });
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = t.first + dx[i];
            int ty = t.second + dy[i];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
            if (arr[ty][tx] == ind || arr[ty][tx] == 0) continue;
            arr[ty][tx] = ind;
            q.push({ tx,ty });
            land[ind].push_back({ tx,ty });
        }
    }
}

void bridgebfs(int ind) {
    queue<element> q;
    bool vis[8] = { 0, };
    for (auto iter = land[ind].begin(); iter != land[ind].end(); iter++) {
        int x = (*iter).first;
        int y = (*iter).second;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
            if (arr[ty][tx]) continue;
            q.push({tx,ty,i,1});
        }
    }
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int tx = t.x + dx[t.d];
        int ty = t.y + dy[t.d];
        if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
        if (vis[arr[ty][tx]]) continue;
        if (!arr[ty][tx]) { q.push({ tx,ty,t.d,t.i + 1 }); continue; }
        if (t.i == 1) continue;
        vis[arr[ty][tx]] = 1;
        pq.push({ ind,arr[ty][tx],0,t.i});
    }
}

int find(int x) {
    if (parent[x] == x) return x;
    return find(parent[x]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 1;
    if (root[a] > root[b]) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
        if (root[a] == root[b]) root[b]++;
    }
    return 0;
}

int mst(int ind) {
    int res = 0,cnt = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (uni(t.x, t.y)) continue;
        res += t.i;
        cnt++;
    }
    if (cnt == ind-3) return res;
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    int ind = 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 1) landbfs(ind++, j, i);
    for (int i = 2; i < ind; i++) parent[i] = i;
    for (int i = 2; i < ind; i++) bridgebfs(i);

    printf("%d", mst(ind));
    return 0;
}