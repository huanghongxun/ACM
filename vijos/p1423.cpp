#include<stdio.h>
#include<string.h>
#define maxn 200
#define INF 200000000
long n,m,cost[maxn+10],map[maxn+10][maxn+10];
int main()
{
	long i,j,k,a,b,c;
	scanf("%ld%ld",&n,&m);
	for(i=1;i<=n;++i)
	scanf("%ld",&cost[i]);
	for(i=1;i<=n;++i)
	for(j=i;j<=n;++j)
	map[i][j]=map[j][i]=INF;
	for(i=1;i<=m;++i)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
		c+=cost[a]+cost[b];
		if(c<map[a][b])
		map[a][b]=c;
	}
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				if(map[i][j]>map[i][k]+map[k][j]-cost[k])
					map[i][j]=map[i][k]+map[k][j]-cost[k];
	if(map[1][1]==INF)
	{
		printf("-1\n");
	}
	else
	{
		printf("%ld\n",map[1][1]-cost[1]);
	}
	return 0;
}
