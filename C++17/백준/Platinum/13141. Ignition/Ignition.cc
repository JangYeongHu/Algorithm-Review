#include <bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> nodes;

int arr[201][201];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n,m; cin >> n >> m;

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if(i!=j)
        arr[i][j] = 1<<29;
    }
  }

  for(int i = 0; i < m; i++) {
    int S,E,L; cin >> S >> E >> L;
    nodes.push_back({S,E,L});
    arr[S][E] = arr[E][S] = min(L,arr[E][S]);
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        arr[i][j] = min(arr[i][k]+arr[k][j],arr[i][j]);
      }
    }
  }
  

  double ans = 1<<29;
  for (int x = 1; x <= n; x++)
  {
    double mx = 0;
    for(auto [s,e,l]: nodes) {
      mx = max(mx,max(arr[s][x],arr[x][e])+(l-abs(arr[s][x]-arr[x][e]))/2.);
    }
    ans = min(mx,ans);
  }
  cout << fixed;
  cout << setprecision(1);
  cout << ans;
}