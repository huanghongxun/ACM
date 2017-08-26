#include <cstdio>
#include <cstring>
const int N = 100005;
char s1[N], s2[N];
int f1[N], f2[N];

void getloop(char *p, int n, int *next, int &loop, int &times) {
	for (int i = 0, j = 2; j <= n; ++j) {
		while (i && p[j] != p[i + 1]) i = next[i];
		if (p[j] == p[i + 1]) ++i;
		next[j] = i;
	}
	loop = n - next[n];
	if (loop != 0 && n % loop == 0) times = n / loop;
	else times = 1, loop = n;
}

int main() {
	int n1, n2, l1, l2, i, t1, t2, ans = 0;
	scanf("%s%s", s1 + 1, s2 + 1);
	n1 = strlen(s1 + 1); n2 = strlen(s2 + 1);
	getloop(s1, n1, f1, l1, t1);
	getloop(s2, n2, f2, l2, t2);
	if (l1 != l2) return puts("0");
	for (i = 1; i <= l1; ++i) if (s1[i] != s2[i]) return puts("0");
	for (i = 1; i <= t1 && i <= t2; ++i)
		if (t1 % i == 0 && t2 % i == 0)
			++ans;
	printf("%d", ans);
	return 0;
}