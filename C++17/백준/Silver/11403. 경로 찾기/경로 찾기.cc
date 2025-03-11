#include <bits/stdc++.h>
using namespace std;
bool graph[100][100];
int n;

void bfs(int x) {
	queue<int> q;
	bool vis[100] = { 0, };
	for (int i = 0; i < n; i++)
		if(graph[x][i]){ q.push(i); vis[i] = 1;
	}
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (!graph[t][i]) continue;
			if (vis[i]) continue;
			vis[i] = 1;
			q.push(i);
		}

	}
	for (int i = 0; i < n; i++)
		cout << vis[i] << " ";
	cout << "\n";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];


	for (int i = 0; i < n; i++)
		bfs(i);

}