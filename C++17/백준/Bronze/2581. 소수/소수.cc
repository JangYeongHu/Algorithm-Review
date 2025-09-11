#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> val;
    vector<int> ch((int) 1e4 + 1, 0);
    for (int i = 2; i < (int) 1e4 + 1; i++) {
        if (!ch[i]) {
            val.push_back(i);
            for (int j = i + i; j < (int) 1e4 + 1; j += i) ch[j] = 1;
        }
    }
    int m;
    cin >> m;
    int n;
    cin >> n;
    int sm = 0;
    int mi = (int) 1e4 + 1;
    for (int i = 0; i < (int) val.size(); i++) {
        if (m <= val[i] && val[i] <= n) {
            sm += val[i];
            mi = min(mi, val[i]);
        }
    }
    if (!sm) cout << -1 << '\n';
    else {
        cout << sm << '\n';
        cout << mi << '\n';
    }
    return 0;
}