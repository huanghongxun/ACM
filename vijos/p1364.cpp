#include <iostream>
using namespace std;
typedef long long ll;
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll a[210][210],f[210][210],m,n,i,j;
int main()
{
	cin>>m>>n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		f[1][i]=a[1][i];
	for(i=2;i<=m;i++)
		for(j=1;j<=n;j++)
			f[i][j]=max(max(f[i-1][j-1],f[i-1][j]),f[i-1][j+1])+a[i][j];
	cout<<max(max(f[m][n/2],f[m][n/2+1]),f[m][n/2+2]) <<endl;
	return 0;
}