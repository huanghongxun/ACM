#include <stdio.h>
#include <string.h>

struct aa {long s,b;}tree[2000];
long c[2000],e[2000],n,dp[1025][200],m,t;

void lian(long a,long b)
{
	if (tree[a].s==0) {tree[a].s=b; return;}
	a=tree[a].s;
	while (tree[a].b!=0) a=tree[a].b;
	tree[a].b=b;
}

void du()
{
	long i,j;
	long a,b;

	memset(dp,128,sizeof(dp)); memset(tree,0,sizeof(tree));
	t=dp[0][0];
	for (i=0; i<=m; i++) dp[0][i]=0;
	scanf("%ld%ld",&n,&m);
	for (i=2; i<=n; i++)
	{
	scanf("%ld",&a);
	lian(a,i);
	}
	for (i=1; i<=n; i++) scanf("%ld",&c[i]);
	for (i=1; i<=n; i++) scanf("%ld",&e[i]);
}

long max(long a,long b){return a>b?a:b;}

long dper(long a,long m)
{
	long i,j,ans=t;

	if (a==0) return 0;
	if (dp[a][m]!=t) 
	return dp[a][m];
	if (c[a]<=m) ans=max(ans,e[a]+dper(tree[a].b,m-c[a]));

	for (i=0; i<=m; i++)
	ans=max(ans,dper(tree[a].s,i)+dper(tree[a].b,m-i));
	dp[a][m]=ans;
	return ans;
}

main()
{
	long ans,i;
	du();
	printf("%ld\n",dper(1,m)); 
	return 0;
}