#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int possible[17];
int dfs(vector<int> info, vector<vector<int>> edges, int wolfs, int sheeps,int ind) {
    int m = sheeps;
    for (auto iter = edges[ind].begin(); iter != edges[ind].end(); iter++) possible[*iter] = 1;
    possible[ind] = 0;
    for (int i = 0; i < info.size(); i++) {
        if (possible[i]) {
            if (info[i] == 0) {
                m = max(m, dfs(info, edges, wolfs, sheeps + 1, i));
            }
            else {
                if (wolfs + 1 < sheeps) {
                    m = max(m, dfs(info, edges, wolfs + 1, sheeps, i));
                }
                else continue;
            }
        }
    }
    possible[ind] = 1;
    for (auto iter = edges[ind].begin(); iter != edges[ind].end(); iter++) possible[*iter] = 0;
    return m;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    possible[0] = 1;
    vector<vector<int>> edge(17);
    for (int i = 0; i < edges.size(); i++) edge[edges[i][0]].push_back(edges[i][1]);
	int answer = dfs(info, edge, 0, 1,0);
    return answer;
}