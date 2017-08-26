#include <cstdio>
#include <cstring>
long n,i,j,tot=0,max;
int a[100001];
long ans[200005];
int main()
{
	memset(ans, -1, sizeof(ans));
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%d", &a[i]);
		if(a[i] == 0) a[i] = -1;
	}
	for(i=1;i<=n;i++)
	{
		tot += a[i];
		if(ans[tot] < 0) ans[tot] = i;
	}
	max = 0;
	for(i = 0; i <= 200000; i++)
		if(max < ans[i]) max = ans[i];
	printf("%d", max);
	return 0;
}