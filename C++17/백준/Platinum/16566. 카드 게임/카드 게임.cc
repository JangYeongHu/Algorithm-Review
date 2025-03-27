#include <bits/stdc++.h>
using namespace std;
int arr[4'000'001], parent[4'000'001];

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) { cin >> arr[i]; parent[i] = i; }
	sort(arr + 1, arr + m + 1);
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		int start = 0, end = m, mid;
		int mx = end;
		while (start <= end) {
			mid = (start + end) / 2;
			if (arr[mid] > num) {
				if (arr[mx] > arr[mid]) mx = mid;
				end = mid - 1;
			}
			else start = mid + 1;
		}
		while (parent[mx] != mx) mx = parent[mx];
		cout << arr[mx] << "\n";
		parent[mx] = mx + 1;

	}
}