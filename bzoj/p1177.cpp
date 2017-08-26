#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define max(i,j) ((i)>(j)?(i):(j))
#define N 2505
int n, m, k, ans, x,i,j;
int a[N][N], b[N][N], c[N][N], d[N][N], s[N][N];
int main() {
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n) FOR(j,1,m) {
		scanf("%d",&x);
		s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
	}
	FORD(i,n,k)FORD(j,m,k)s[i][j]-=s[i-k][j]+s[i][j-k]-s[i-k][j-k];

	FOR(i,k,n)FOR(j,k,m)a[i][j]=max(s[i][j],max(a[i-1][j],a[i][j-1]));
	FOR(i,k,n)FORD(j,m,k)b[i][j]=max(s[i][j],max(b[i-1][j],b[i][j+1]));
	FORD(i,n,k)FOR(j,k,m)c[i][j]=max(s[i][j],max(c[i+1][j],c[i][j-1]));
	FORD(i,n,k)FORD(j,m,k)d[i][j]=max(s[i][j],max(d[i+1][j],d[i][j+1]));

	FOR(i,k,n-k)FOR(j,k,m-k)ans=max(ans,a[i][j]+b[i][j+k]+c[i+k][m]);
	FOR(i,k,n-k)FOR(j,k+k,m)ans=max(ans,b[i][j]+d[i+k][j]+a[n][j-k]);
	FOR(i,k+k,n)FOR(j,k,m-k)ans=max(ans,c[i][j]+d[i][j+k]+a[i-k][m]);
	FOR(i,k,n-k)FOR(j,k,m-k)ans=max(ans,a[i][j]+c[i+k][j]+b[n][j+k]);

	FOR(i,k,n)FOR(j,k+k,m-k)ans=max(ans,s[i][j]+a[n][j-k]+b[n][j+k]);
	FOR(i,k+k,n-k)FOR(j,k,m)ans=max(ans,s[i][j]+a[i-k][m]+c[i+k][m]);

	printf("%d\n",ans);
	return 0;
}