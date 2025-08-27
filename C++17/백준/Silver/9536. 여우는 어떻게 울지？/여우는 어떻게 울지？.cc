#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);

        vector<string> words;
        stringstream ss(line);
        string w;
        while (ss >> w) words.push_back(w);
        set<string> nf;

        while (1) {
            getline(cin, line);
            if (line == "what does the fox say?") break;

            stringstream s2(line);
            string a, goes, sound;
            s2 >> a >> goes >> sound;
            nf.insert(sound);
        }

        for (string& x : words)
            if (!nf.count(x)) cout << x << " ";
        cout << "\n";
    }
    return 0;
}