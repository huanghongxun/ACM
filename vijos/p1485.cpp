#include <stdio.h>

int main()
{
	long i, j, n, m;
	long f[31][31];
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++) f[0][i] = 0;
	f[0][0] = 1;
	for(i = 1; i <= m; i++)
		for(j = 0; j < n; j++)
			f[i][j] = f[i - 1][(j - 1 + n) % n] + f[i - 1][(j + 1) % n];
	printf("%d", f[m][0]);
	return 0;
}