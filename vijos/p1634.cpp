#include <stdio.h>
#define INF 0x7fffffff
long k, i, j, n, zs;
long f[10000001];
long a[1000001], t[1000001];
int main() {
	scanf("%ld%ld", &n, &k);
	for(int i = 1; i <= k; i++)
		scanf("%ld%ld", &a[i], &t[i]);
	j=k;f[n+1]=0;
	for(int i = n; i >= 1; i--) {
		f[i] = INF;
		if(a[j]!=i) f[i] = f[i+t[j]];
		else while(a[j]==i) {
			zs = t[j]+f[i+t[j]];
			if(zs<f[i]) f[i]=zs;
			j--;
		}
	}
	printf("%ld", f[1]);
	return 0;
}