#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    a--;
    b--;
    int answer = 0;
    while (a != b) {
        cout << a << " " << b << "\n";
        a /= 2;
        b /= 2;
        answer++;
    }
    return answer;
}