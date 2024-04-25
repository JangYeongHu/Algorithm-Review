#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> redge[20001];
bool vis[20001];
queue<pair<int, int>> q;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, mx = 0;
    for (auto iter = edge.begin(); iter != edge.end(); iter++) {
        redge[(*iter)[0]].push_back((*iter)[1]);
        redge[(*iter)[1]].push_back((*iter)[0]);
    }
    q.push({ 1,0 });
    vis[1] = 1;
    while (!q.empty()) {
        int t = q.front().first;
        int c = q.front().second;
        if (c > mx) { mx = c; answer = 1; }
        else if (c == mx) { answer++; }
        q.pop();
        for (auto iter = redge[t].begin(); iter != redge[t].end(); iter++) {
            if (vis[*iter]) continue;
            vis[*iter] = 1;
            q.push({ *iter,c + 1 });
        }
    }

    return answer;
}