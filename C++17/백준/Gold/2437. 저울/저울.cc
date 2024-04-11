#include <cstdio>
#include <algorithm>
int arr[1002];
int sum[1002];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {scanf("%d", arr + i);}
	arr[n + 1] = 1 << 30;
	std::sort(arr + 1, arr + n + 2);
	for (int i = 1; i <= n; i++) sum[i] = arr[i] + sum[i - 1];
	int ind = 0;
	while (sum[ind] + 1 >= arr[ind+1]) ind++;
	printf("%d", sum[ind]+1);
	return 0;
}