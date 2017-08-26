#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxm=2005;
const int maxn=6005;
const int inf=0x3fffffff;
int a[maxn];
int n,m;
int f[maxn][maxm];
int sq(int v,int b) {
	return (a[v]-a[b])*(a[v]-a[b]);
}
int min(int a,int b) {
	return a<b?a:b;
}
int main() {
	scanf("%d%d", &m, &n); int i,j;
	for(i=n;i>=1;i--) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			f[i][j]=inf;
	for(i=1;i<=m;i++)
		for(j=i*3;j<=n;j++)
			f[j][i]=min(min(f[j][i],f[j-1][i]),f[j-2][i-1]+sq(j,j-1));
	cout<<f[n][m]<<endl;
	return 0;
}