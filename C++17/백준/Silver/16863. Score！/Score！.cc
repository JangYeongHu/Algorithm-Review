#include <bits/stdc++.h>
using namespace std;

int s_to_time(string s) {
    string h, m;
    if (s[1] == ':') {
        h = s.substr(0, 1);
        m = s.substr(2, 2);
    } else {
        h = s.substr(0, 2);
        m = s.substr(3, 2);
    }
    return stoi(h) * 60 + stoi(m);
}

string time_to_s(int time) {
    string h = to_string(time / 60);
    string m = to_string(time % 60);
    if (m.length() == 1) m = "0" + m;
    return h + ":" + m;
}

int main() {
    int n; cin >> n;

    int H = 0, A = 0;
    int Ht = 0, At = 0;
    int nt = 0;

    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int score; cin >> score;
        string hm; cin >> hm;

        int cur = s_to_time(hm);

        if (H > A) Ht += cur - nt;
        else if (A > H) At += cur - nt;

        if (c == 'H') H += score;
        else A += score;

        nt = cur;
    }

    int end = s_to_time("32:00");
    if (H > A) Ht += end - nt;
    else if (A > H) At += end - nt;

    cout << ((H > A) ? "H" : "A") << " " << time_to_s(Ht) << " " << time_to_s(At);
}
