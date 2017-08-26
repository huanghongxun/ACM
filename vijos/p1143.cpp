#include <iostream>
#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;i++)
using namespace std;
const int maxn=25;
const int maxm=50;
int f[maxn][maxn][maxn][maxm];
int a[maxn][maxn];
int n,m;
int main()
{
	cin>>n; int i,j,k,l;
	FOR(i,1,n) FOR(j,1,n) cin>>a[i][j];
	m=n+n-1;
	FOR(l,1,m) FOR(i,1,n) FOR(j,1,n) FOR(k,1,n) {
		f[i][j][k][l]=max(f[i][j][k][l-1],max(f[i][j][k-1][l-1],max(f[i-1][j][k][l-1],max(f[i][j-1][k][l-1],max(f[i-1][j-1][k][l-1],max(f[i-1][j][k-1][l-1],max(f[i][j-1][k-1][l-1],f[i-1][j-1][k-1][l-1])))))));
		if(i==j)
			if(i==k)
				f[i][j][k][l]+=a[i][l-i+1];
			else
				f[i][j][k][l]+=(a[j][l-j+1]+a[k][l-k+1]);
		else if(j==k)
			f[i][j][k][l]+=(a[i][l-i+1]+a[k][l-k+1]);
		else if(i==k)
			f[i][j][k][l]+=(a[j][l-j+1]+a[k][l-k+1]);
		else
			f[i][j][k][l]+=(a[i][l-i+1]+a[j][l-j+1]+a[k][l-k+1]);
	}
	cout<<f[n][n][n][m]<<endl;
	return 0;
}