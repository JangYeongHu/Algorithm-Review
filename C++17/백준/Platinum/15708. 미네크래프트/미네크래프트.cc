#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,t,p; cin >> n >> t >> p;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int l = 0;
    priority_queue<int> pq;
    int mx = 0,now = 0;
    for(int i = 0; i < n; i++) {
        l += arr[i];
        pq.push(arr[i]);
        now++;
        while(l > t) {
            if(pq.empty()) {
                cout << mx;
                return 0;
            }
            l -= pq.top(); pq.pop();
            now--;
        }
        l += p;
        mx = max(mx,now);
    }
    cout << mx;
}