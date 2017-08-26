#include <cstdio>
#include <algorithm>
#define ll long long
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
ll read() {
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,T,top;
int u[10005], v[10005], d[10005], a[105][105];
char ch[10005][2];
int xx[4] = {0, 0, -1, 1}, yy[4] = {1, -1, 0, 0}; //RLUD
int dfs(int x, int y, int now) {
	if (x > n || y > m || x < 1 || y < 1) return 0;
	if (a[x][y]) return 0;
	if (now == top) return 1;
	FOR(i,1,v[now]) {
		int nx = x + xx[d[now]] * i, ny = y + yy[d[now]] * i;
		if (nx > n || ny > m || nx < 1 || ny < 1) return 0;
		if (a[nx][ny]) return 0;
		if (i >= u[now] && dfs(nx,ny,now+1)) return 1;
	}
	return 0;
}
int main() {
	T=read();
	while(T--) {
		n=read();m=read();
		FOR(i,1,n) FOR(j,1,m) a[i][j]=read();
		top=0;
		while(1) {
			top++;
			u[top]=read();v[top]=read();
			if(!u[top]&&!v[top])break;
			scanf("%s",ch[top]+1);
			if(ch[top][1]=='R')d[top]=0;
			else if(ch[top][1]=='L')d[top]=1;
			else if(ch[top][1]=='U')d[top]=2;
			else d[top]=3;
		}
		int ans=0;
		FOR(i,1,n) FOR(j,1,m) ans+=dfs(i,j,1);
		printf("%d\n",ans);
	}
	return 0;
}
