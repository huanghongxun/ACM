#include <cstdio>
#include <cstring>
const int N = 100005;
char p[N];
int next[N], dp[N], len[N];

int main() {
	int i, j, n, tot = 0;
	scanf("%s", p + 1);
	n = strlen(p + 1);
	for (i = 0, j = 2; j <= n; ++j) {
		while (i && p[j] != p[i + 1]) i = next[i];
		if (p[i + 1] == p[j]) ++i;
		next[j] = i;
	}
	for (i = n; i; i = next[i]) len[++tot] = i;
	for (i = n; i; --i) dp[next[i]] += ++dp[i];
	printf("%d\n", tot);
	for (i = tot; i; --i) printf("%d %d\n", len[i], dp[len[i]]);

	return 0;
}