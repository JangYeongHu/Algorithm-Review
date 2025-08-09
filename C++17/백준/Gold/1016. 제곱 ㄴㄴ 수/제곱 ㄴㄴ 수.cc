#include <bits/stdc++.h>
using namespace std;

int main() {
    long long mn, mx; cin >> mn >> mx;

    int limit = 1000001;
    vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;
    vector<long long> primes;

    for (int i = 2; i < limit; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (long long j = (long long)i * i; j < limit; j += i) {
            is_prime[j] = false;
        }
    }

    vector<bool> nnsu(mx - mn + 1, false);
    int cnt = 0;

    for (auto s : primes) {
        long long sq = s * s;
        if (sq > mx) break;

        long long start = (mn + sq - 1) / sq * sq;
        for (long long j = start; j <= mx; j += sq) {
            if (!nnsu[j - mn]) {
                nnsu[j - mn] = true;
                cnt++;
            }
        }
    }

    int total = (int)(mx - mn + 1);
    cout << total - cnt << "\n";

    return 0;
}