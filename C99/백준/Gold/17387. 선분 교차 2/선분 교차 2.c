#include <stdio.h>
typedef struct pos{
	long long x;
	long long y;
} pos;

int ccw(pos a, pos b, pos c) {
	long long n = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
	if (!n) return 0;
	return (int)(n / (n > 0 ? n : -n));
}
int cmp(pos a, pos b,pos t) {
	if (a.x == b.x) return a.y <= t.y && b.y >= t.y || a.y >= t.y && b.y <= t.y;
	return a.x <= t.x && b.x >= t.x || a.x >= t.x && b.x <= t.x;
}

int main() {
	int r = 0; 
	pos a, b, c, d;
	scanf("%lld %lld %lld %lld", &a.x, &a.y, &b.x, &b.y);
	scanf("%lld %lld %lld %lld", &c.x, &c.y, &d.x, &d.y);

	if (ccw(a, b, c) != ccw(a, b, d))
	{if (ccw(c, d, a) != ccw(c, d, b)) r = 1;}
	else if (!ccw(c, d, a) && !ccw(c, d, b) && (cmp(a, b, c) || cmp(a, b, d) || cmp(c, d, a) || cmp(c, d, b))) r = 1;
	printf("%d", r);
	return 0;
}