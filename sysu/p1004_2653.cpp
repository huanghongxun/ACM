#include <cstdio>
#include <cstring>
const int N = 1e6 + 5;
char A[N], B[N];

int main() {
	char *a = A, *b = B;
	int la, lb, i;
	scanf("%s%s", a, b);
	la = strlen(a); lb = strlen(b);
	for (i = 0; i < la; ++ i)
		if (a[i] != '0') {
			a = a + i;
			la -= i;
			break;
		}
	if (i == la) a += i, la = 0;

	for (i = 0; i < lb; ++ i)
		if (b[i] != '0') {
			b = b + i;
			lb -= i;
			break;
		}
	if (i == lb) b += i, lb = 0;

	if (la > lb)
		puts(">");
	else if (la < lb)
		puts("<");
	else {
		int cmp = strcmp(a, b);
		if (cmp < 0) puts("<");
		else if (cmp > 0) puts(">");
		else puts("=");
	}
	return 0;
}