#define MAX 100001
#include <iostream>
#include <queue>
using namespace std;
queue<pair<int,int>> q;
bool vis[MAX];
int main() {
	int n, k;
	cin >> n >> k;
	q.push({ n,0 });
	vis[n] = 1;
	while (1) {
		auto t = q.front();
		q.pop();
		if (t.first == k) {
			cout << t.second; break;
		}
		int x[] = {t.first + 1,t.first - 1,t.first * 2};
		for (int a : x) {
			if (a < 0 || a >= MAX) continue;
			if (vis[a]) continue;
			vis[a] = 1;
			q.push({a,t.second+1});
		}
	}
	return 0;
}