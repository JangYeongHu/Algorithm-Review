#include <bits/stdc++.h>
using namespace std;

long long hashh(vector<int> & arr) { return arr[0] * 601 * 601 * 601 + arr[1] * 601 * 601 + arr[2] * 601 + arr[3]; }
unordered_map<char, int> ch;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    ch['A'] = 0; ch['T'] = 1; ch['G'] = 2; ch['C'] = 3;
    while (t--) {
        int k; cin >> k;
        string w; cin >> w;
        unordered_map<long long, int> umm;
        vector<int> arr(4,0);
        for (int i = 0; i < k; i++)
            arr[ch[w[i]]]++;
        umm[hashh(arr)] = 1;
        for (int i = k; i < w.length(); i++) {
            arr[ch[w[i - k]]]--;
            arr[ch[w[i]]]++;
            umm[hashh(arr)]++;
        }
        int ans = 0;
        for (auto& i : umm) {
            ans = max(i.second, ans);
        }

        cout << ans << "\n";
    }
    return 0;
}