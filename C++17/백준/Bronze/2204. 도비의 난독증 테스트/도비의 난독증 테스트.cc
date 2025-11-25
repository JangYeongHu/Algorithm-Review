#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	while(1) {
		int n; cin >> n;
		if(n==0) break;
		vector<string> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end(),
	[](string a,string b) {
		for (int i = 0; i < min(a.length(),b.length()); i++)
		{
			char x = a[i], y = b[i];
			if(x > 'Z') x -= 'a';
			else x -= 'A';
			if(y > 'Z') y -= 'a';
			else y -= 'A';
			if(x!=y) return x < y;
		}
		return a.length() < b.length();
	});
	cout << arr[0] << "\n";
	}
}