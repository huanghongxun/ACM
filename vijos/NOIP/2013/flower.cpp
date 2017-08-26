/*
#include <cstdio>
#include <algorithm>
#define N 100005
using namespace std;

int f[2][N], c[2][N], h[N];
int n, i, maxh, ans=0;

int lowbit(int t) {
	return t & (-t);
}

void change(int *c, int i, int x){
	for(;i<=n;i+=lowbit(i)) {
		printf("%d\n", i); c[i]=max(c[i],x);
	}
}

int query(int *c, int i) {
	int ans=0;
	for(;i>0;i-=lowbit(i)) ans=max(ans,c[i]);
	return ans;
}

int main() {

	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&h[i]);
		maxh=max(maxh,h[i]);
	}
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++) {
		f[0][i]=max(query(c[1],h[i]-1)+1,f[0][i]);
		f[1][i]=max(query(c[0],maxh-h[i]-1)+1,f[1][i]);
		change(c[1], maxh-h[i], f[0][i]); change(c[0], h[i], f[1][i]);
		ans=max(ans,max(f[0][i],f[1][i]));
	}
	printf("%d\n", ans);

	return 0;
}*/


#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100010
#define lowbit(i) ((i)&(-(i)))
#define H 1000010
#define ford(i,x) for(i=x;i;i-=lowbit(i))
#define rep(i,x) for(i=x;i<=maxh;i+=lowbit(i))

int t0[H], t1[H], h[N], n, maxh, i;
int f[N][2], ans=0;

void modify(int *t, int x, int y) {
	rep(x,x) t[i]=max(t[i],y);
}

int query(int *t, int x) {
	int ans=0;
	ford(x,x) ans=max(ans,t[i]);
	return ans;
}

int main() {
	ans=0;
	scanf("%d", &n);
	for(i=0;i<n;i++) {
		scanf("%d",&h[i]);
		maxh=max(maxh,++h[i]);
		f[i][0]=f[i][1]=1;
	}
	maxh++;
	memset(t0,0,sizeof(t0));
	memset(t1,0,sizeof(t1));
	for(i=0;i<n;i++) {
		f[i][0]=max(query(t0, h[i]-1)+1,f[i][0]);
		f[i][1]=max(query(t1, maxh-h[i]-1)+1,f[i][1]);
		modify(t0, h[i], f[i][1]);
		modify(t1, maxh-h[i], f[i][0]);
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	printf("%d\n", ans);

	return 0;
}