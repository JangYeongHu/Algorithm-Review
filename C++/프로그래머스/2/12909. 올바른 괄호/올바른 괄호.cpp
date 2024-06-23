#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++) {
        if(s.at(i) == '(') st.push('(');
        else if(st.size() == 0) return false;
        else if(st.top() == '(') st.pop();
        else return false;
    }
    if(st.size() == 0) return true;
    return false;
}