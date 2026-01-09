#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> nodes[3001];
vector<tuple<int,int,int>> allNodes;
using ll = long long;
int dis[3000 + 1];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N,M,K;  cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int a,b,l; cin >> a >> b >> l;
        nodes[a].push_back({b,l});
        nodes[b].push_back({a,l});
        allNodes.push_back({a,b,l});
    }
    vector<int> mall;
    priority_queue<pair<int,int>> pq;
    for(int i = 1; i <= N; i++) dis[i] = 1<<29;
    for (int i = 0; i < K; i++)
    {
        int t; cin >> t;
        mall.push_back(t);
        pq.push({t,0});
        dis[t] = 0;
    }

	while (!pq.empty()) {
		auto [u,tl] = pq.top(); pq.pop();

		if (tl > dis[u]) continue;

		for (auto [v,l] : nodes[u]) {
			if (dis[u] + l < dis[v]) {
				dis[v] = dis[u] + l;
				pq.push({ v, dis[v] });
			}
		}
	}

    double ans = 0;

    for(auto [a,b,l]: allNodes) {
        ans = max(ans,(max(dis[a],dis[b])+(l-abs(dis[a]-dis[b]))/2.));
    }
    cout << round(ans);
}