#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int dp[500][500] = { 0 };
    dp[0][0] = triangle[0][0];
    int t = 1;
    for (int i = 1; i < triangle.size(); i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < t; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        dp[i][t] = dp[i - 1][t-1] + triangle[i][t];
        t++;
    }
    int answer = 0;
    for (int i = 0; i < t; i++) answer = max(answer, dp[t - 1][i]);
    return answer;
}