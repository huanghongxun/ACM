// UVALive 6174, HDU 4486
#include <cstdio>
int main()
{
	int t,n,i,m,ans,temp1,temp2,a,b,c,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		temp1=m/3;
		ans=0;
		for(a=1;a<=temp1;a++)
		{
			temp2=(m-a)/2;//b上限
			temp=0;
			b=(m/2-a+1)>a?(m/2-a+1):a;//b下限
			if(a==b)
			{
				ans--;
				temp=a;
			}
			if(temp!=temp2&&temp2==m-a-temp2)//判断b==c，并防止一个等腰三角形三角形减去两次
				ans--;
			ans+=2*(temp2-b+1);//不管等腰三角形先都加2，在上面判断减一
		}
		printf("%d %d\n",n,ans);
	}
	return 0;
}