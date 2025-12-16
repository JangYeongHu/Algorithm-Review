#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    ll w;
    cin >> n >> w;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    ll mn = 0;
    vector<ll> lower, higher;
    
    for(ll x : arr) {
        if(x <= w) lower.push_back(x);
        else higher.push_back(x);
    }
    
    sort(lower.rbegin(), lower.rend());
    if(!lower.empty()) {
        mn += abs(lower[0] - w);
        for(size_t i = 1; i < lower.size(); i++) {
            mn += min(abs(lower[i] - lower[i-1]), abs(lower[i] - w));
        }
    }
    
    sort(higher.begin(), higher.end());
    if(!higher.empty()) {
        mn += abs(higher[0] - w);
        for(size_t i = 1; i < higher.size(); i++) {
            mn += min(abs(higher[i] - higher[i-1]), abs(higher[i] - w));
        }
    }

    vector<ll> mxa1(n);
    vector<ll> mxa2(n);
    for(ll i = 0,idx = 0; i < n && idx < n; i++, idx+=2)
        mxa1[idx] = arr[i];

    for(int i = n-1,idx = 1; i > 0 && idx < n; i--, idx+=2)
        mxa1[idx] = arr[i];

    for(int i = 0,idx = 1; i < n && idx < n; i++, idx+=2)
        mxa2[idx] = arr[i];

    for(int i = n-1,idx = 0; i > 0 && idx < n; i--, idx+=2)
        mxa2[idx] = arr[i];

    ll mx1=abs(mxa1[0]-w),mx2=abs(mxa1[n-1]-w);
    ll mx3=abs(mxa2[0]-w),mx4=abs(mxa2[n-1]-w);

    for(int i = 1; i < n; i++) {
        mx1 += max(abs(mxa1[i]-mxa1[i-1]),abs(w-mxa1[i]));
    }

    for(int i = n-2; i >= 0; i--) {
        mx2 += max(abs(mxa1[i]-mxa1[i+1]),abs(w-mxa1[i]));
    }

    for(int i = 1; i < n; i++) {
        mx3 += max(abs(mxa2[i]-mxa2[i-1]),abs(w-mxa2[i]));
    }

    for(int i = n-2; i >= 0; i--) {
        mx4 += max(abs(mxa2[i]-mxa2[i+1]),abs(w-mxa2[i]));
    }

    cout << mn << " " << max({mx1,mx2,mx3,mx4});
}