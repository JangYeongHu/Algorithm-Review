#include <bits/stdc++.h>
using namespace std;
int arr[100][100];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j]; 
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;cin>>t;
            cout<<t+arr[i][j] << " ";
        }
        cout << "\n";
        
    }
    
    
    return 0;
}