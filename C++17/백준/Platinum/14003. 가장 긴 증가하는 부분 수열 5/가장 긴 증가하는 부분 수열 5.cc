#include <cstdio>
int t_in[1000002];
int arr[1000002];
int X[1000002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n + 2; i++) arr[i] = 1 << 30;
	arr[0] = 1 << 31;
	for (int i = 1; i <= n; i++) scanf("%d", t_in + i);
	for (int i = 0; i < n; i++)
	{
		int t, ind = 1 << 30;
		t = t_in[i + 1];
		int start = 0, end = n + 1, mid;
		while (start < end) {
			mid = (start + end) / 2;
			if (arr[mid] >= t) end = mid;
			else start = mid + 1;
		}
		arr[end] = t;
		X[i + 1] = end;
	}
	int res, ind;
	for (int i = 1; i < n + 2; i++)
		if (arr[i] == 1 << 30) {
			res = i - 1;
			break;
		}
	ind = res;
	for (int i = n; i >= 0 && ind > 0; i--)
		if (X[i] == ind) { arr[ind] = t_in[i]; ind--; }
	printf("%d\n", res);
	for (int i = 1; i <= res; i++) printf("%d ", arr[i]);
}