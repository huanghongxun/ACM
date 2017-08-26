/*

f[i][j][k]
i表示选到第i个花盆
j表示选到第j种花
k表示第j种花选了k个。

f[i][j][k]+=f[i-k][p][q].
p=1..j-1
q=0..a[p]
*/

#include <iostream>
#include <cstring>
using namespace std;
#define N 105
#define MOD 1000007

int n, m;

int f[N][N];
int a[N];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<=a[1];i++) f[1][i]=1;

	for(int i=2;i<=n;i++)
	{
		f[i][0]=1;
		for(int j=1;j<=m;j++)
			for(int k=0;k<=a[i];k++)
				if(j-k>=0)
					f[i][j]=(f[i][j]+f[i-1][j-k])%MOD;
	}
	cout<<f[n][m];
	return 0;
}