#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 200002

typedef long long ll;

struct USER{
	ll s, w, num;
} *u;

bool operator <(const USER &a, const USER &b)
{
	return a.w<b.w;
}

int cmp(const USER &a, const USER &b)
{
	if(a.s==b.s)
		return a.num<b.num;
	return a.s>b.s;
}

int n, r, q, i, j;
int winp, failp;
USER win[N], fail[N];

USER *merge(USER *a, USER *b, int la, int lb)
{
	USER *ans = new USER[la+lb+1];
	int i = 1, j = 1, k = 1;
	while(i<=la&&j<=lb)
	{
		if(cmp(a[i],b[j]))
			ans[k++] = a[i++];
		else
			ans[k++] = b[j++];
	}
	while(i<=la) ans[k++] = a[i++];
	while(j<=lb) ans[k++] = b[j++];
	return ans;
}

int main()
{
	scanf("%d%d%d", &n, &r, &q);
	u = new USER[2*n+1];
	for(i = 1; i <= 2*n; i++)
		u[i].num = i;
	for(i = 1; i <= 2*n; i++)
		scanf("%I64d", &u[i].s);
	for(i = 1; i <= 2*n; i++)
		scanf("%I64d", &u[i].w);
	sort(u+1,u+2*n+1,cmp);
		
	for(i = 1; i <= r; i++)
	{
		winp = 0;
		failp = 0;
		for(j = 1; j <= n; j++)
		{
			if(u[2*j-1]<u[2*j])
			{
				u[2*j].s++;
				win[++winp] = u[2*j];
				fail[++failp] = u[2*j-1];
			}
			else
			{
				u[2*j-1].s++;
				win[++winp] = u[2*j-1];
				fail[++failp] = u[2*j];
			}
		}
		u = merge(win,fail,n,n);
	}
	printf("%I64d", u[q].num);
	
	return 0;
}