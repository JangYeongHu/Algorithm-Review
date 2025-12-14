#include <bits/stdc++.h>
using namespace std;
int tree[808080];
int arr[202020];

void init(int start,int end,int n) {
    if(start==end) {
        tree[n] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    if((start+end)%2==0)mid--;
    init(start,mid,n*2);
    init(mid+1,end,n*2+1);
    tree[n] = gcd(tree[n*2],tree[n*2+1]);
}

int query(int start,int end,int n) {
    if(start==end) return arr[start];
    int mid = (start+end)/2;
    if((start+end)%2==0)mid--;
    return max(query(start,mid,n*2)+tree[n*2+1],query(mid+1,end,n*2+1)+tree[n*2]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i+1];
    }

    init(1,n,1);

    cout << query(1,n,1);
}