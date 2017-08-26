#include <cstdio>
struct x
{
	long z, c, v;
} a[10001];
long b[10001], f[10001], g[10001];
long n,m,i,j,k;
int main()
{
	scanf("%d%d", &n, &m);
	for(i = 1; i <= 3; i++)
		scanf("%d%d%d", &a[i].z, &a[i].c, &a[i].v);
	for(i = 1; i <= n; i++) {
		scanf("%d%d", &b[i], &k);
		for(j = m; j >= b[i]; j--)
			if(g[j - b[i]] + f[i] > g[j])
				g[j] = g[j - b[i]] + f[i];
	}
	printf("%d", g[m]);
	return 0;
}