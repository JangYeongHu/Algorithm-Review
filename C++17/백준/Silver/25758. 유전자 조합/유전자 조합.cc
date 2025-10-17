#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    unordered_set<string> us;
    unordered_set<char> ans;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (us.find(s) != us.end()) ans.insert(max(s[0], s[1]));
        us.insert(s);
    }

    vector<string> arr;
    for (string s : us) arr.push_back(s);
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size(); j++) {
            if (i == j) continue;
            ans.insert(max(arr[i][0], arr[j][1]));
        }


    vector<char> aans;
    for (char c : ans) aans.push_back(c);
    sort(aans.begin(), aans.end());
    cout << aans.size() << "\n";
    for (char c : aans) cout << c << " ";
}