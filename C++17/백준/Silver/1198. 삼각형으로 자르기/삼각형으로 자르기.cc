#include <bits/stdc++.h>
using namespace std;

double calculateArea(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    return abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) / 2.0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N)) return 0;

    vector<pair<long long, long long>> jum(N);
    for (int i = 0; i < N; i++) {
        cin >> jum[i].first >> jum[i].second;
    }

    double maxArea = 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                double currentArea = calculateArea(
                    jum[i].first, jum[i].second,
                    jum[j].first, jum[j].second,
                    jum[k].first, jum[k].second
                );
                if (maxArea < currentArea) {
                    maxArea = currentArea;
                }
            }
        }
    }
    cout << fixed;
    cout.precision(1);
    cout << maxArea << endl;

    return 0;
}