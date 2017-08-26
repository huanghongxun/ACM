#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int dp[2001][2001];
int mn (int a,int b,int c)
{
	return min(min(a,b),c);
}
int main()
{
	string str1,str2;
	int k,i,j;
	cin>>str1>>str2>>k;
	int n=str1.size(),m=str2.size();
	dp[0][0]=0;
	for (i=1;i<=n;i++) dp[i][0]=i*k;
	for (j=1;j<=m;j++) dp[0][j]=j*k;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			dp[i][j] = mn(
				dp[i-1][j-1] + abs(str1[i-1]-str2[j-1]),
				dp[i][j-1]+k,
				dp[i-1][j]+k
			); 
	cout<<dp[n][m];
	return 0;
}