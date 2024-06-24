#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_q,min_q,dmax_q,dmin_q;
    for(auto iter = operations.begin(); iter != operations.end(); iter++) {
        cout << max_q.size() << " " << min_q.size() << "\n";
        string s = *iter;
        char command = s.at(0);
        int data = stoi(s.substr(2));
        if(command == 'I') {
            max_q.push(data);
            min_q.push(-data);
        } else {
            if(max_q.empty()) continue;
            if(data == -1) {
                dmax_q.push(-min_q.top());
                min_q.pop();
            } else {
                dmin_q.push(-max_q.top());
                max_q.pop();
            }
            while(!max_q.empty() && !dmax_q.empty()) {
                if(dmax_q.top() != max_q.top()) break;
                dmax_q.pop(); max_q.pop();
            }
            while(!min_q.empty() && !dmin_q.empty()) {
                 if(dmin_q.top() != min_q.top()) break;
                dmin_q.pop(); min_q.pop();
            }
        }
    }
    if(max_q.empty()) return {0,0};
    return {max_q.top(),-min_q.top()};
}