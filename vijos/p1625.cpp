#include <stdlib.h>
#include <stdio.h>
long f[500000]={0};
long a[500000],b[500000];
long n,v,t1;
int main()
{
	scanf("%d %d %d",&v,&n,&t1);
	int i,j,k,l;
	for(i=1;i<=n;i++)
		scanf("%d %d",&a[i],&b[i]);
	for(i=1;i<=n;i++)
		for(j=t1-b[i];j>=0;j--)
		{
			if(f[j+b[i]]<f[j]+a[i])
				f[j+b[i]]=f[j]+a[i];
		}
	for(i=0;i<=t1;i++)
		if(f[i]>=v)
		{
			printf("%d",t1-i);
			return 0;
		}
	printf("Impossible");
	return 0;
}