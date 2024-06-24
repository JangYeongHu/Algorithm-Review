#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n>s) return {-1};
    int mok = s/n;
    int na = s%n;
    vector<int> answer;
    for(int i = 0; i < n; i++) answer.push_back(mok);
    for(int i = n-1; i >= n-na; i--) answer[i]++;
    return answer;
}