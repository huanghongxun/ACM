#include <stdio.h>
#define FOR(i,j,k) for(i=j;i<=k;i++)
int fa[1000005];
bool vis[1000005]={0};
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y) {
	if(x<y){int t=x;x=y;y=t;}
	vis[y]=1;fa[y]=x;
}
int main() {
	int n,i,x,y;
	scanf("%d", &n);
	FOR(i,1,n+1)fa[i]=i;
	FOR(i,1,n) {
		scanf("%d%d", &x, &y);
		int p=find(x),q=find(y);
		if(p==q) vis[p] = 1;
		else merge(p,q);
	}
	FOR(i,1,n+1) if (!vis[i]) { printf("%d",i-1); break; }
	return 0;
}