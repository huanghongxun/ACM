#include <cstdio>
#include <cmath>

int i,j,k,n,t,pre,last,ma;
int a[11],f[11][1001][1001];

int main() {
	scanf("%d",&n);
	k=(int)trunc(log10(n)/log10(2))+1;
	printf("%d ", k);
	for(i=1;i<=k;i++) a[i]=1<<(i-1);
	f[1][1][1]=1;
	for(pre=1;pre<k;pre++)
		for(last=pre;last<=a[pre];last++)
			for(ma=1;ma<=n;ma++) {
				if(f[pre][last][ma]>0) {
					for(i=last+1;i<=ma+1;i++) {
						if(ma+i<n) f[pre+1][i][ma+i]+=f[pre][last][ma];
						else f[pre+1][i][n]+=f[pre][last][ma];
					}
				}
			}
	int tot=0;
	for(i=1;i<=n;i++)
		tot+=f[k][i][n];
	printf("%d", tot);
	return 0;
}