#include <stdio.h>
#include <stdlib.h>
long long b[61][61],v;
long i,j,k,n,t1,t2,w1,w2,a[1001][3];
int main()
{
	scanf("%ld%ld%ld",&n,&t1,&t2);
	for(i=1;i<=n;i++)
		scanf("%ld%ld%ld",&a[i][0],&a[i][1],&a[i][2]);
	b[0][0]=1;
	for(i=1;i<=n;i++)
		for(j=t1;j>=0;j--)
			for(k=t2;k>=0;k--)
				if(b[j][k]!=0)
				{
					w1=j+a[i][0];
					w2=k+a[i][1];
					if(w1>t1)
						w1=t1;
					if(w2>t2)
						w2=t2;
					v=b[j][k]+a[i][2];
					if(b[w1][w2]==0)
						b[w1][w2]=v;
					else if(v<b[w1][w2])b[w1][w2]=v;
				}
	printf("%lld\n", (b[t1][t2]-1)*2);
	return 0;
}