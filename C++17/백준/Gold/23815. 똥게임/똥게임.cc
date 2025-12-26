#include <bits/stdc++.h>
using namespace std;
int dp[101010][2];

int calc(int a,int b,char c) {
    switch(c) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        default: return a/b;
    }
}

int main() {
    dp[0][0] = dp[0][1] = 1;
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    bool ch = 0;
    for(int i = 1; i <= n; i++) {
        string a,b; cin >> a >> b;
        dp[i][1] = max(calc(dp[i-1][1],a[1]-'0',a[0]),calc(dp[i-1][1],b[1]-'0',b[0]));
        dp[i][0] = max({dp[i-1][1],calc(dp[i-1][0],a[1]-'0',a[0]),calc(dp[i-1][0],b[1]-'0',b[0])});
        if(dp[i][1] <= 0) ch=1;
        if(ch) dp[i][1] = -1;
        if(i==1) dp[i][0] = 1;
        if(dp[i][0] <= 0 && dp[i][1] <= 0) {
            cout << "ddong game";
            return 0;
        }
    }
    cout << max(dp[n][0],dp[n][1]);
    return 0;
}