#include <cstdio>
#include <cstring>
#define maxlongint 0x7fffffff
long rmb[101], rp[101], time[101];
long max, m, r, n, i, j, k, sum;
long f[101][101];
long t[101][101];

int main()
{
	scanf("%ld", &n);
	for(i = 1; i <= n; i++)
		scanf("%ld%ld%ld", &rmb[i], &rp[i], &time[i]);
	scanf("%ld%ld", &m, &r);
  
	memset(f,0,sizeof(f));
	f[m][r]=0;
	max=-maxlongint;
	sum=maxlongint;
 

	for(i = 1; i <= n; i++)
		for(j = m; j >= 0; j--)
			for(k = r; k >= 0; k--)
			{
				if (j>=rmb[i] && k>=rp[i] && f[j][k]<=f[j-rmb[i]][k-rp[i]]+1)
				{
					if(f[j][k]<f[j-rmb[i]][k-rp[i]]+1)
					{
						f[j][k]=f[j-rmb[i]][k-rp[i]]+1;
						t[j][k]=t[j-rmb[i]][k-rp[i]]+time[i];
					}
					else
					{
						if(t[j][k]>t[j-rmb[i]][k-rp[i]]+time[i])
						{
							f[j][k]=f[j-rmb[i]][k-rp[i]]+1;
							t[j][k]=t[j-rmb[i]][k-rp[i]]+time[i];
						}
					}
				}
			}
	for(j = 0; j <= m; j++)
		for(k = 0; k <= r; k++)
			if(max<=f[j][k])
			{
 				if(max<f[j][k])
				{
					max=f[j][k];
					sum=t[j][k];
				}
				else if(sum>t[j][k])
				{
					max=f[j][k];
					sum=t[j][k];
				}
			}
	printf("%ld", sum);
	return 0;
}