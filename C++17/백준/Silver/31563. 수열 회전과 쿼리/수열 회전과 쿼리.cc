#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<long long> arr(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    int idx = 0;
    while (q--) {
        int x; cin >> x;
        if (x == 3) {
            int a, b; cin >> a >> b;
            a = ((a - 1 - idx) % n + n) % n + 1;
            b = ((b - 1 - idx) % n + n) % n + 1;

            if (a <= b) {
                cout << arr[b] - arr[a-1] << "\n";
            } else {
                cout << (arr[n] - arr[a-1]) + arr[b] << "\n";
            }
        }
        else {
            int k; cin >> k;
            if (x == 1) idx = (idx + k) % n;
            else idx = (idx - k) % n;
            idx = (idx + n) % n;
        }
    }
    return 0;
}