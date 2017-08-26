#include <cstdio>
#include <cstring>
#include <iostream>
#define N 200005
#define maxlen 200005
using namespace std;
int sum[N], rank[N], trank[N], sa[N], height[N], tsa[N];
char str[N]; int n;

void get_sa()
{
	int p;
	for(int i = 1; i <= n; i++)
		printf("%d ", str[i]);
	for (int i=1; i<=n; i++) trank[i]=(int)str[i];
	for(int i = 1; i <= n; i++)
		printf("%d ", str[i]);
	for (int i=1; i<=n; i++) sum[ trank[i] ]++;
	for (int i=1; i<=n; i++) sum[i]+=sum[i-1];
	for (int i=n; i>0; i--) 
		sa[ sum[ trank[i] ]-- ]=i;
}

void sorting(int j)//基数排序
{
	memset(sum,0,sizeof(sum));
	for (int i=1; i<=n; i++) sum[ rank[i+j] ]++;
	for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
	for (int i=n; i>0; i--)
            tsa[ sum[ rank[i+j] ]-- ]=i;
       //对第二关键字计数排序，tsa代替sa为排名为i的后缀是tsa[i] 

	memset(sum,0,sizeof(sum));
	for (int i=1; i<=n; i++) sum[ rank[i] ]++;
	for (int i=1; i<=maxlen; i++) sum[i]+=sum[i-1];
	for (int i=n; i>0; i--)
            sa[ sum[ rank[ tsa[i] ] ]-- ]= tsa[i]; 
       //对第一关键字计数排序,构造互逆关系 
}

void get_rank()
{
	int p;
	rank[ sa[1] ]=1;
	for (int i=2,p=1; i<=n; i++)
	{
		if (trank[ sa[i] ]!=trank[ sa[i-1] ]) p++;
		rank[ sa[i] ]=p;
	}//第一次的sa与rank构造完成
	for (int j=1; j<=n; j*=2)
	{
		sorting(j);
		trank[ sa[1] ]=1; p=1; //用trank代替rank 
		for (int i=2; i<=n; i++)
		{
			if ((rank[ sa[i] ]!=rank[ sa[i-1] ]) || (rank[ sa[i]+j ]!=rank[ sa[i-1]+j ])) p++;
			trank[ sa[i] ]=p;//空间要开大一点，至少2倍
		}
		for (int i=1; i<=n; i++) rank[i]=trank[i];
	}
}

void get_height()
{
	int j, k = 0;
	for(int i = 1; i <= n; i++) {
		if(rank[i] == 1)
		{
			height[rank[i]] = 0;
			continue;
		}
		j = sa[rank[i] - 1];
		while(str[i+k] == str[j+k]) k++;
		height[rank[i]] = k;
		if(k > 0) k--;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	gets(str);
	for(int i = 1; i <= n; i++)
		scanf("%c", &str[i]);
	for(int i = 1; i <= n; i++)
		printf("%d|", str[i]);
	get_sa();
	for(int i = 1; i <= n; i++)
		printf("%d ", trank[i]);
	puts("");
	get_rank();
	get_height();
	long long ans=0;
    for (int i=1;i<=n;i++) {
        ans+=(i-height[i]);
    }
    printf("%lld", ans);
	return 0;
}