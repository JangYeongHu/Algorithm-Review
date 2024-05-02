#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for (int i = 1; i * i < 2000000; i++) {
        if (yellow / i - (double)yellow / i) continue;
        int a = i, b = yellow / i;
        if (2 * (a + b) + 4 == brown) return { b + 2,a + 2 };
    }
}