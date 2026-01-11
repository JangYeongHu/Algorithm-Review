#include <bits/stdc++.h>
using namespace std;
int arr[15];
int N;

bool Check(int idx) {
	for (int i = 0; i < idx; i++)
		if (arr[i] == arr[idx] || abs(idx - i) == abs(arr[idx] - arr[i]))
			return 0;
	
	return 1;
}

int Queen(int idx) {
	if(N==idx)
		return 1;
	
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		arr[idx] = i;
		if(!Check(idx)) continue;
		ans += Queen(idx+1);
	}
	return ans;
}

int main() {
	cin >> N;
	cout << Queen(0);
	return 0;
}