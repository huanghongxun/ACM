#include <cstdio>
#include <cstring>

#define FOR(i,j,k) for(i=j;i<=k;i++)
#define N 1005
#define M 250005
struct Hungary {
    int to[M], next[M], head[N], cnt;
	int matchu[N], matchv[N];
	bool vis[N]; int n;
	bool dfs(int u) {
        if(vis[u]) return false;
        vis[u] = 1;
		for(int i = head[u]; i!=-1; i = next[i]) {
			int v = to[i];
			if(matchv[v] == -1 || dfs(matchv[v])) {
				matchv[v] = u;
				matchu[u] = v;
				return true;
			}
		}
		return false;
	}
    Hungary(int n) {
		this->n = n;
        memset(head,-1,sizeof(head));
		memset(matchv,-1,sizeof(matchv));
		memset(matchu,-1,sizeof(matchu));
    }
    void add(int a,int b) {
        to[cnt]=a,next[cnt]=head[b],head[b]=cnt++;
    }
    int hungary() {
		int i, res = 0;
		FOR(i,1,n)
			if(matchu[i] == -1) {
				memset(vis,0,sizeof(vis));
				if(dfs(i)) res++;
			}
		return res;
    }
};

int main() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	Hungary *h = new Hungary(n);
	FOR(i,1,m) {
		int x,y;
		scanf("%d%d", &x, &y);
		h->add(x,y);
		h->add(y,x);
	}
	printf("%d\n", h->hungary()/2);
	FOR(i,1,n) printf("%d ", h->matchv[i]==-1?0:h->matchv[i]);
	
	return 0;
}