#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define rep(i,j,k) for(i=j;i<k;i++)
#define inf 0x7ffffff
#define max(i,j) ((i)>(j)?(i):(j))
#define min(i,j) ((i)<(j)?(i):(j))
typedef long long ll;

#define FILENAME "road"

// =A= lalalalayayayayahahahahapapapapa

#define MAXM 210000
#define MAXN 11000

struct Graph {
	int h[MAXM], t[MAXM], p[MAXM], cnt;
	
	Graph() {
		cnt = 0;
		memset(h,-1,sizeof(h));
	}

	void add(int x, int y) {
		p[cnt]=h[x];
		t[cnt]=y;
		h[x]=cnt++;
	}
} ga, gb;

int connectable[MAXN];
int neighor[MAXN];
int n, m, s, t;

void readin() {
	scanf("%d%d", &n, &m);
	int i, x, y;
	rep(i,0,m) {
		scanf("%d%d", &x, &y);
		if(x==y) continue;
		ga.add(x,y);
		gb.add(y,x);
	}
	scanf("%d%d", &s, &t);
	
	memset(connectable, 0, sizeof(connectable));
}

int q[MAXN], vis[MAXN], dis[MAXN];

// maybe O(M)?
void work() {
	memset(vis,0,sizeof(vis));
	int f = 0, r = 0, u;
	q[r++] = t;
	vis[t] = 1;
	while(f < r) {
		u = q[f++];
		connectable[u]=1;
		for(int i=gb.h[u];i!=-1;i=gb.p[i]) {
			int v = gb.t[i];
			if(!vis[v]) {
				q[r++] = v;
				vis[v] = 1;
			}
		}
	}
	FOR(u,1,n) {
		neighor[u]=1;
		for(int i=ga.h[u];i!=-1;i=ga.p[i]) {
			int v = ga.t[i];
			if(!connectable[v]) {
				neighor[u]=0;
				break;
			}
		}
	}
}

// maybe O(M)?
int spfa() {
	int f = 0, r = 0, i;
	memset(vis,0,sizeof(vis));
	FOR(i,0,n) dis[i]=inf;
	q[r++] = s;
	vis[s] = 1;
	dis[s] = 0;
	while(f < r) {
		int u = q[f++];
		for(i=ga.h[u];i!=-1;i=ga.p[i]) {
			int v=ga.t[i];
			if(!neighor[v]) continue;
			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				if(!vis[v]) {
					q[r++] = v;
					vis[v] = 1;
				}
			}
		}
		vis[u]=0;
	}
	if(dis[t] == inf)
		return -1;
	else
		return dis[t];
}

void print() {
	printf("%d", spfa());
}

int main() {
	readin();
	work();
	print();
	
	return 0;
}
