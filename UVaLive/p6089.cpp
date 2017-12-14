// UVALive 6089
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int iabs(int s)
{
	if(s<0)
		return -s;
	return s;
}
struct node
{
	int b,c;//b 9的数量，C相差
	int d;//d 字典序
};
struct node p[11000];

int countNine(int x) {
	int count = 0;
	for (; x; x /= 10) if (x % 10 == 9) ++count;
	return count;
}

node find(int x, int mark, int s, int ss) {
	node h;
	int a,b,count2=0;
	a=x/60+s,b=x%60+ss;
	count2=countNine(a) + countNine(b);
	h.b=count2;
	h.c=iabs(x-mark);
	h.d=(x/60+s)*100+(x%60+ss);
	return h;
}

bool cmp(node a,node b) {
	if(a.b!=b.b)
		return a.b>b.b;
	if(a.c!=b.c)
		return a.c<b.c;
	return a.d<b.d;
}

int main() {
	int m, s, ans;
	int l, r, i;
	while (scanf("%d:%d", &m, &s) != EOF) {
		if (m==0 && s==0)
			break;
		ans=m*60+s;
		l = ceil(ans * 9 / 10.0);
		r = floor(ans * 11 / 10.0);

		if (ans % 10 == 0)
			l++, r--;
		int cnt=0;
		for(i=l;i<=r;i++)
		{
			p[cnt++]=find(i,ans,0,0);
			if(i/60>0 && i%60+60<100)
				p[cnt++]=find(i,ans,-1,60);
		}
		sort(p,p+cnt,cmp);
		printf("%02d:%02d\n",p[0].d / 100, p[0].d % 100);
	}
	return 0;
}