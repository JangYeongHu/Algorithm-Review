#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
int prefix[101][101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    int k, a, b; cin >> k >> a >> b;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    while (t--) {
        memset(prefix, 0, sizeof(prefix));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1]
                - prefix[i - 1][j - 1] + (arr[i][j] == '*');

        char temp[101][101];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int nx = max(1, j - k), ny = max(1, i - k);
                int mx = min(m, j + k), my = min(n, i + k);

                int s = prefix[my][mx] - prefix[my][nx - 1]
                    - prefix[ny - 1][mx] + prefix[ny - 1][nx - 1]
                    - (arr[i][j] == '*');

                if (arr[i][j] == '.') {
                    if (s > a && s <= b) temp[i][j] = '*';
                    else temp[i][j] = '.';
                }
                else {
                    if (s >= a && s <= b) temp[i][j] = '*';
                    else temp[i][j] = '.';
                }
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                arr[i][j] = temp[i][j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << arr[i][j];
        cout << "\n";
    }
    return 0;
}