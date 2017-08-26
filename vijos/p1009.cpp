# include <stdio.h>
__int64 gcd(__int64 a,__int64 b){
	if(b==0)
		return a;
	return gcd(b,a%b);
}
void exgcd(__int64 a,__int64 b,__int64 &m,__int64 &n){
	if(b==0)
	{
		m=1;
		n=0;
		return;
	}
	exgcd(b,a%b,m,n);
	__int64 t;
	t=m, m=n, n=t-a/b*n;
}
int main()
{
	__int64 x,y,m,n,l,a,b,c,k1,k2,r,t;
	while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
	{
		a=n-m;
		b=l;
		c=x-y;
		r=gcd(a,b);
		if(c%r)
		{
			printf("Impossible\n");
			continue;
		}
		a/=r, b/=r, c/=r;
		exgcd(a,b,k1,k2);
		t=c*k1/b;
		k1=c*k1-t*b;
		if(k1<0)
			k1+=b;
		printf("%I64d\n",k1);
	}
	return 0;
}