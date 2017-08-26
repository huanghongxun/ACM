#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;i++)
const int N=1001,M=201000,inf=10000000;
int dis[N], vis[N], cnt[N];
int edge, n, m;
int head[N], next[M], to[M], wei[M], q[M];
inline bool spfa() {
    int u,i,f=0,r=0;
    FOR(i,0,n) vis[i]=cnt[i]=0,dis[i]=inf;
    vis[0] = 1; dis[0] = 0; q[r++]=0;
    while(f<r) {
        u=q[f++]; vis[u]=0;
        for(i=head[u];i!=-1;i=next[i])
            if (dis[to[i]]>dis[u]+wei[i]) {
                dis[to[i]]=dis[u]+wei[i];
                if(!vis[to[i]]) {
                    vis[to[i]]=1;
                    q[r++]=to[i];
                    if(++cnt[to[i]]>n) return 0;
                }
            }
    }
    return 1;
}
inline void add(int u, int v, int w) {
    to[edge]=v; wei[edge]=w; next[edge]=head[u]; head[u]=edge++;
}
int main() {
    char ch[5];
    int i,u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF) {
        edge=0;
        memset(head,-1,sizeof head);
        FOR(i,1,m) {
            scanf("%s",ch);
            if(ch[0] == 'P') {
                scanf("%d%d%d",&u,&v,&w);
				add(v,u,w);
				add(u,v,-w);
            } else {
                scanf("%d%d",&u,&v);
                add(u,v,-1);
            }
        }
        FOR(i,1,n) add(0,i,0);
        if(!spfa()) printf("Unreliable\n");
        else printf("Reliable\n");
    }
    return 0;
}
