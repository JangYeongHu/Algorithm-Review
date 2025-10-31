#include <bits/stdc++.h>
using namespace std;
int dx[] = { -1,0,1,1,1,0,-1,-1 }, dy[] = { -1,-1,-1,0,1,1,1,0 };
int main() {
	string arr[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> arr[i][j];
	vector<pair<string,vector<string>>> ans;
	for (int i = 1; i <= 8; i++) {
		int cy = 4 + dy[i - 1] * 3, cx = 4 + dx[i - 1] * 3;
		vector<string> temp;
		for (int j = 1; j <= 8; j++) {
			temp.push_back(arr[dy[j - 1] + cy][dx[j - 1] + cx]);
		}
		sort(temp.begin(), temp.end());
		ans.push_back({ arr[cy][cx],temp });
	}

	sort(ans.begin(), ans.end());

	for (int i = 1; i <= 8; i++) {
		cout << "#" << i << ". " << ans[i - 1].first << "\n";
		for (int j = 1; j <= 8; j++)
			cout << "#" << i << "-" << j << ". " << ans[i - 1].second[j - 1] << "\n";
	}

	return 0;
}