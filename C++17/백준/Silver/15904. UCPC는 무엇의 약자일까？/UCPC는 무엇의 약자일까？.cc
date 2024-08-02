#include <cstdio>
char d[] = { 'U','C','P','C' };
int main(){
	int ind = 0;
	char c;
	while(scanf("%c", &c) != EOF)
		if (ind == 4) break;
		else if (c == d[ind]) ind++;
	if (ind == 4) printf("I love UCPC");
	else printf("I hate UCPC");
	return 0;
}