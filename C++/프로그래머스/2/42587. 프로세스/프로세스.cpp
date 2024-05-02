#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < priorities.size(); i++) { pq.push(priorities[i]); q.push(priorities[i]); }
    int answer = 1;
    while (!q.empty()) {
        cout << q.size() << " " << location << "\n";
        if (pq.top() == q.front()) {
            if (location == 0) return answer;
            else location--;
            answer++;
            pq.pop();
            q.pop();
        }
        else {
            if (location == 0) location = q.size() - 1;
            else location--;
            q.push(q.front());
            q.pop();
        }
    }
}