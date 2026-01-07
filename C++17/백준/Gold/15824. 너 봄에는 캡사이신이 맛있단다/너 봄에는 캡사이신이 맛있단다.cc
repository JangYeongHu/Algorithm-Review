#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using ll = long long;

ll PowMod(ll a, ll b, ll c){
if(c == 1) return 0;
ll res = 1;
for(a%=c; b; b >>= 1, a = a * a % c) if(b & 1) res = res * a % c;
return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll ans = 0;
  sort(arr.begin(),arr.end());
  for(int i = 0; i < n; i++) {
    ll p = (PowMod(2, i, MOD) - 1 + MOD) % MOD;
    ll x = (arr[i] * p % MOD - arr[n-i-1] * p % MOD + MOD) % MOD;
    ans = (ans + x) % MOD;
  }
  cout << ans; 
}