#include <iostream>
#include <cstring>
using namespace std;
#define N 105

typedef long long ll;

ll f[N][N];
ll dx[] = {-1, 1, 2,2,1,-1,-2,-2};
ll dy[] = {-2,-2,-1,1,2, 2, 1,-1};

ll n, m, cn, cm, i, j;

int main()
{
	memset(f, -1, sizeof(f));
	cin>>n>>m>>cn>>cm;
	for(i=0;i<=n;i++)
		f[i][0] = 1;
	for(j=0;j<=m;j++)
		f[0][j] = 1;
	f[cn][cm] = 0;
	for(i=0;i<8;i++) {
		if(dx[i]+cn<0||dy[i]+cm<0||dx[i]+cn>n||dy[i]+cm>m) continue;
		f[dx[i]+cn][dy[i]+cm]=0;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(f[i][j]==-1)
				f[i][j] = f[i-1][j]+f[i][j-1];
	if(f[n][m]==-1) f[n][m]=0;
	cout<<f[n][m];
	return 0;
}