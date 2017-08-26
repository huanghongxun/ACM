#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <functional>
#include <utility>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef long long ll;
#define inf 0x7ffffff
#define eps 1e-6
#define rep(i,j,k) for(i=j;i<k;i++)
#define repd(i,j,k) for(i=j-1;i>=k;i--)
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
#define foreach(i,j) for(i=j.begin();i!=j.end();i++)

ll read() {
    ll x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

#define N 505
#define M 10005

int disA[N], disB[N], vis[N], q[N*5], n, m;
int h[N], p[M], t[M], w[M], cnt=0;
int dist[N][N];

void add(int a, int b, int c) {
	p[cnt]=h[a]; t[cnt]=b; w[cnt]=c; h[a]=cnt++;
}

void spfa(int s, int *dis) {
	int f=0,r=0,i,u,v;
	FOR(i,0,n) dis[i]=inf,vis[i]=0;
	q[r++]=s;
	dis[s]=0;
	while(f<r) {
		u=q[f++];
		for(i=h[u];i!=-1;i=p[i]) {
			v=t[i];
			if (dis[v]>dis[u]+w[i]) {
				dis[v]=dis[u]+w[i];
				if(!vis[v]) {
					q[r++]=v;vis[v]=1;
				}
			}
		}
		vis[u]=0;
	}
}

int main() {
	int x,y,z,op;
	n=read(),m=read();
	FOR(x,0,n) FOR(y,0,n) dist[x][y]=inf;
	FOR(x,0,n) dist[x][x]=0,h[x]=-1;
	while(m--) {
		op=read();
		if(op) {
			x=read(),y=read(),z=read();
			spfa(x,disA);spfa(y,disB);
			add(x,y,z);add(y,x,z);
			FOR(x,1,n) FOR(y,1,n)
				dist[x][y]=min(dist[x][y],min(disA[x]+disB[y]+z,disA[y]+disB[x]+z));
		} else {
			x=read(),y=read();
			printf("%d\n", dist[x][y]==inf?-1:dist[x][y]);
		}
	}
	
	return 0;
}

