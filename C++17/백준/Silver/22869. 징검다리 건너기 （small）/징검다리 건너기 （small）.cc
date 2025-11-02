#include <bits/stdc++.h>
using namespace std;

int arr[5000];
bool possible[5001];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    possible[0] = 1;
    for (int j = 1; j < n; j++)
        for (int i = j - 1; i >= 0; i--)
            if ((j - i) * (1 + abs(arr[i] - arr[j])) <= k && possible[i]) {
                possible[j] = 1; break;
            }

    if (possible[n-1]) cout << "YES";
    else cout << "NO";
}