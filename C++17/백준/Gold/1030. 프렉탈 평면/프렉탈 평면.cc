#include <bits/stdc++.h>
using namespace std;

bool check(int s,int n,int k,int x,int y) {
    bool c1 = 0,c2 = 0;
    int gap = (n-k)/2;
    for(int i = 0; i < s; i++) {
        if(gap <= x%n && (n-gap-1) >= x%n && gap <= y%n && (n-gap-1) >= y%n) {
            return 1;
        }
        x/=n;
        y/=n;
    }
    return 0;
}

int main() {
    int s,n,k,r1,r2,c1,c2;
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1;j <= c2; j++)
        {
            if(check(s,n,k,j,i)) cout << 1;
            else cout << 0;
        }
        cout << "\n";
    }
    
    return 0;
}