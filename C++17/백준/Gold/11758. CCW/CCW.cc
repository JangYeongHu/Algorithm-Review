#include <iostream>
#include <vector>

using namespace std;

long long ccw_part(int x1, int y1, int x2, int y2) {
    return (long long)x1 * y2 - (long long)y1 * x2;
}

int signum(long long n) {
    return (n > 0) - (n < 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p[3][2];
    for (int i = 0; i < 3; i++) {
        cin >> p[i][0] >> p[i][1];
    }

    long long cnt = 0;
    for (int i = 0; i < 3; i++) {
        cnt += ccw_part(p[i][0], p[i][1], p[(i+1)%3][0], p[(i+1)%3][1]);
    }

    cout << signum(cnt) << endl;

    return 0;
}