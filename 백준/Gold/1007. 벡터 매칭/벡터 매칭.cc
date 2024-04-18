#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
pair<long long, long long> pos[20];
int n;
long long mn;
void bf(int ind,int cnt,bool vis[]) {
	if (n/2 == cnt) {
		long long x = 0, y = 0;
		for (int i = 0; i < n; i++)
			if (vis[i]) { x += pos[i].first; y += pos[i].second; }
			else { x -= pos[i].first; y -= pos[i].second; }
		mn = min(mn,x*x+y*y); return;
	};
	for (int i = ind+1; i < n; i++) {
		vis[i] = 1;
		bf(i,cnt + 1, vis);
		vis[i] = 0;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		bool vis[20] = { 0, };
		mn = (long long)1<<60;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%lld %lld", &pos[i].first, &pos[i].second);
		bf(0,0, vis);
		printf("%lf\n", sqrt(mn));
	}
	return 0;
}