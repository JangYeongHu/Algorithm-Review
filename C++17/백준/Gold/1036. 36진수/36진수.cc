#include <bits/stdc++.h>
using namespace std;

int cnt[50][50];

int make_idx(char c) {
    if(c >= '0' && c <= '9') {
        return c-'0';
    } else {
        return c-'A'+10;
    }
}

char make_char(int v) {
    if (v < 10) return '0' + v;
    return 'A' + (v - 10);
}

string sm(string a, string b) {
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int va = 0, vb = 0;
        if (i >= 0) va = make_idx(a[i--]);
        if (j >= 0) vb = make_idx(b[j--]);
        int s = va + vb + carry;
        carry = s / 36;
        int d = s % 36;
        res.push_back(make_char(d));
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n; cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        arr.push_back(s);
    }

    int k; cin >> k;

    vector<pair<string,char>> cases;

    for (int i = 0; i < 36; i++) {
        char t = make_char(i);
        string ans = "0";
        vector<string> temp;
        for(string s: arr) {
            for(int j = 0; j < s.length(); j++) {
                if(s[j] == t) s[j] = 'Z';
            }
            temp.push_back(s);
        }

        for(string s: temp)
            ans = sm(ans,s);

        cases.push_back({ans,t});

    }

    sort(cases.begin(),cases.end(),
    [](pair<string,char> a, pair<string,char> b) {
        string as = a.first, bs = b.first;

        if(as.length() != bs.length()) return as.length() > bs.length();

        for(int i = 0; i < as.length(); i++) {
            if(as[i] != bs[i]) return as[i] > bs[i];
        }

        return a.second > b.second;
    });

    vector<char> crit;

    for(int i = 0; i < k; i++) {
        crit.push_back(cases[i].second);
    }

    string ans = "0";
    for (char t: crit) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr[i].length(); j++) {
                if(arr[i][j] == t) arr[i][j] = 'Z';
            }
        }
    }

    for(string s: arr)
        ans = sm(ans,s);

    cout << ans;

    return 0;
}