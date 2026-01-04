#include <bits/stdc++.h>
using namespace std;

int arr[3000][3000];
int ptr[3000];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; 
    cin >> n >> m >> q;

    for(int i = 0; i < n; i++) {
        ptr[i] = i;
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    }

    while(q--) {
        int cmd, i, j; 
        cin >> cmd >> i >> j;
        if(cmd == 0) {
            int k; cin >> k;
            arr[ptr[i]][j] = k;
        } else {
            swap(ptr[i], ptr[j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[ptr[i]][j] << " ";
        }
        cout << "\n";
    }
}