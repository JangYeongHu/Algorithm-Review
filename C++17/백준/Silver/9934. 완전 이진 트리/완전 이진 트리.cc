#include <cstdio>
#include <vector>

int arr[2000];
std::vector<int> v[10];
void tree(int start,int end,int height) {	
	int mid = (start + end) / 2;
	v[height].push_back(arr[mid]);
	if (start == end) return;
	tree(start, mid - 1,height+1);
	tree(mid + 1, end,height+1);

}
int main() {
	int n;
	scanf("%d", &n);
	int c = 1;
	for (int i = 0; i < n; i++) c *= 2;
	for (int i = 0; i < c-1; i++) scanf("%d", arr + i);
	tree(0,c-2,0);
	for (int i = 0; i < n; i++) {
		for (auto iter = v[i].begin(); iter != v[i].end(); iter++) printf("%d ", *iter);
		printf("\n");
	}
	return 0;
}