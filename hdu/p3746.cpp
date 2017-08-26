#include <cstdio>
#include <cstring>
const int N = 100005;
char p[N];
int next[N];
int main() {
	int t, i, j, n, loop;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", p + 1);
		n = strlen(p + 1);
		for (i = 0, j = 2; j <= n; ++j) {
			while (i && p[j] != p[i + 1]) i = next[i];
			if (p[j] == p[i + 1]) ++i;
			next[j] = i;
		}
		loop = n - next[n];
		printf("%d\n", !next[n] ? n : (n % loop == 0 ? 0 : loop - n % loop));
	}
	return 0;
}