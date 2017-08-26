#include <iostream>
using namespace std;
int main()
{
	int dp[101][101][11],num[101][3],n,m,k,sum[3][101][101];
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));
	cin >> n >> m >> k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin >> num[i][j];
	for (int s=1;s<=m;s++)
	{
		for (int i=1;i<=n;i++)
		{
			sum[i][i]=num[i];
			for (int j=i+1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+num[j];
		}
	}
	for (int l=1;l<=k;l++)
		for (int i=1;i<=n;i++)
			for (int j=0;j<=i;j++)
			{
				dp[i][j][l]=dp[j][l];
				if (j>0) dp[i][j][l]=max(dp[i][j][l],dp[i][j-1][l]);
				for (int s=1;s<=i;s++)
					dp[i][j][l]=max(dp[i][j][l],dp[j][l-1]+sum[1][i]);
				for (int s=1;s<=j;s++)
					dp[i][j][l]=max(dp[i][j][l],dp[i][l-1]+sum[2][j]);
				if (i==j){
					for (int s=1;s<=i;s++)
						dp[i][j][l]=max(dp[i][j][l],dp[l-1]+sum[1][i]+sum[2][i]);
				}
			}
	cout << dp[n][n][k] << endl;
	return 0;
}