#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k; cin >> k;
    for (int j = 0; j < k; j++) {
        int n, m, T; cin >> n >> m >> T;
        vector<double> mn(n + 1);

        for (int a = 0; a < m; a++) {
            int i, t; double d;
            cin >> i >> t >> d;
            if (0 <= T - t && T - t < 1000)
                mn[i] += d;
        }

        double Y = 0.0, N = 0.0;
        for (int a = 1; a <= n; a++) {
            char c; cin >> c;
            if (c == 'Y')
                Y += 1.0;
            else
                N += 1.0 / (1.0 + mn[a] / 10000.0);
        }

        cout << "Data Set " << j + 1 << ":\n";
        cout << fixed << setprecision(2) << Y << " " << N << "\n\n";
    }
    return 0;
}