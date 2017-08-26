#include <iostream>
#include <cmath>
using namespace std;
int i,j,n,it,mb,temp;
int x[2800],y[2800],num[2800];
void init()
{
	cin >> n;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		cin >> it;
		x[it]=i;
		y[it]=j;
	}
}
int main()
{
	init();
	num[n*n]=0;
	for(i=n*n-1;i>=1;i--)
	{
		mb=0;
		for(j=i+1;j<=n*n;j++)
		{
			temp=num[j]+(abs(x[j]-x[i])+abs(y[j]-y[i]))*(abs(x[j]-x[i])+abs(y[j]-y[i]));
			if(temp>mb) mb=temp;
		}
		num[i]=mb;
	}
	cout << num[1] << endl;
	return 0;
}