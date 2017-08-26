#include <cstdio>
#include <cstdlib>
#define max(a,b) ((a)>(b)?(a):(b))
long n,v,k,i,j,m;
float a;
float f[201][201];
long g[201];

int main() {
	scanf("%ld%ld%ld", &n, &v, &k);
	for(i = 2; i <= n; i++)
		scanf("%ld", &g[i]);
	if(k+g[n]>=v) f[n][v] = v;
	for(i = n-1;i >= 2; i--)
		for(j = g[i]; j <= g[i] + k; j++)
			if(f[i+1][j-1] > 0 || f[i+1][j] > 0 || f[i+1][j+1] > 0)
				f[i][j]=max(f[i+1][j-1],max(f[i+1][j],f[i+1][j+1])) + j;
	for(j = g[2]; j <= g[2] + 2; j++)
		if(f[2][j] > a) a = f[2][j];
	if(a > 0) {
		a /= n - 1;
		printf("%.2f", a);
	} else {
		puts("REN JIU SHI BU NENG REN CI!");
	}
	return 0;
}