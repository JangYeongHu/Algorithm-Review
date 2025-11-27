#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	int n; cin >> n;
	vector<ll> arr(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			bool c = 0;
			for (int k = i+1; k < j; k++)
			{
				if((j-k)*(arr[k]-arr[i]) >= (arr[j]-arr[k])*(k-i)) {
					c = 1; break;
				}
			}
			if(!c) {
				ans[i]++; ans[j]++;
			}
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		mx = max(ans[i],mx);
	}
	cout << mx;

}