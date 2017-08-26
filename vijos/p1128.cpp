#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long n,m,ans=0;
short b[5000000]={0},c[30]={0};
long a[30];

short sushu(long x)//是素数返回1，否则返回0 
{
long j,t;

if (x==2) return 1;
if (x<2) return 0;
t=sqrt(x);
for (j=2;j<=t;j++)
if (x%j==0) return 0;
return 1;
}

void init()
{
long i;

scanf("%ld%ld",&n,&m);
for (i=1;i<=n;i++)
scanf("%ld",&a[i]);
}

void DFS(long deep,long sum,long t)
{
long i;
short flag;

if (deep==m)
{
if (/*(b[sum]==0)&&*/(sushu(sum)==1)) ans++;
b[sum]=1;
return;
}
for (i=t;i<=n;i++)
{
if (c[i]==0)
{
c[i]=1;
DFS(deep+1,sum+a[i],i);
c[i]=0;
}
}
}

void print()
{
printf("%ld\n",ans);
}

int main()
{
init();
DFS(0,0,1);
print();
return 0;
}