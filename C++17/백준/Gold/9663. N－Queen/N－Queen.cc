#include <bits/stdc++.h>
using namespace std;
int arr[15];
int s, cnt = 0;
bool check(int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[n] || abs(n - i) == abs(arr[n] - arr[i]))
            return true;
    }
    return false;
}

void queen(int n) {
    if (n == s) {
        cnt++;
        return;
    }
    for (int i = 0; i < s; i++) {
        arr[n] = i;
        if (check(n)) continue;
        queen(n + 1);
    }
}

int main() {
    cin >> s;
    queen(0);
    cout << cnt;
    return 0;
}