#include <stdio.h>
long tmax=0;
long n,a[100000][3];
long max(long a,long b)
{
	return (a>b)? a:b; 
}
long dp(int p,bool lar)
{
	long x[2]={0,0};
	long i;
	if(lar)
		x[p-1]=a[0][p];
	else 
		x[p]=a[0][p];
	for(i=1;i<n;i++)
		if(lar=!lar) 
		{
			if(x[0]>x[1])
				x[1]=x[0]+a[i][2];
			else
				x[1]+=a[i][2];
			if(x[0]>0)
				x[0]+=a[i][1]; 
		}
		else
		{
			if(x[1]>x[0])
				x[0]=x[1]+a[i][0];
			else 
				x[0]+=a[i][0];
			if(x[1]>0)
				x[1]+=a[i][1];
		}
	lar=!lar;
	if(p=1)
		if(lar)
			return x[0];
		else
			return x[1];
	else
		return max(x[0],x[1]);
}
int main()
{
	long i;
	scanf("%ld", &n);
	for(i = 0; i < n; i++)
		scanf("%ld%ld%ld", &a[i][0], &a[i][1], &a[i][2]);
	tmax=max(tmax,dp(2,true));
	tmax=max(tmax,dp(1,true));
	tmax=max(tmax,dp(1,false));
	tmax=max(tmax,dp(0,false));
	printf("%ld", tmax);
	return 0; 
}