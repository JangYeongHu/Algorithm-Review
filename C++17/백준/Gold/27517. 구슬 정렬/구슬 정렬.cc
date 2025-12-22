#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void prt(__int128 x) {
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    if (x > 9) prt(x / 10);
    cout << (char)('0' + x % 10);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<long long> arr(n),cp(n);
    for(int i = 0; i < n; i++) {cin >> arr[i];cp[i] = arr[i];}
    sort(arr.begin(),arr.end());
    __int128_t ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (cp[i]-arr[i])*(n-i-1);
    }
    prt(ans%MOD);
    return 0;
}