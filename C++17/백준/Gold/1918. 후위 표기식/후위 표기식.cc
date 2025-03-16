#include <bits/stdc++.h>
using namespace std;
stack<char> st;

int oper(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '(') return 3;
}

int main() {
	string s;
	cin >> s;
	for (char c : s) {
		if (c >= 'A' && c <= 'Z') { cout << c; continue; };
		if (st.empty()) { st.push(c); continue; }
		if (c == ')') { while (st.top() != '(') { cout << st.top(); st.pop(); } st.pop(); continue; }
		while (oper(st.top()) >= oper(c) && st.top() != '(') {
			cout << st.top(); st.pop(); if (st.empty()) break;
		}
		st.push(c);
	}
	while(!st.empty()) { cout << st.top(); st.pop(); }
}