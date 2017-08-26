#include <cstdio>
#include <cstring>
const int N=1001,M=200001,inf=1000000000;
#define FOR(i,j,k) for(i=j;i<=k;i++)
int read() {
    int s=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*f;
}
int head[N], next[M], to[M], wei[M], cnt = 0, n, m;
bool spfa(int s) {
    static int vis[N], tot[N], dis[N], q[N*128];
    int f=0,r=0,i,u;
    memset(vis,0,sizeof vis);
    memset(tot,0,sizeof tot);
    memset(dis,127,sizeof dis);
    vis[s]=1;q[r++]=s;dis[s]=0;
    while(f<r) {
        u=q[f++];
        for(i=head[u];i;i=next[i])
            if (dis[to[i]]>dis[u]+wei[i]) {
                dis[to[i]]=dis[u]+wei[i];
                if (!vis[to[i]]) {
                    vis[to[i]]=1; q[r++]=to[i];
                	if(++tot[to[i]]>n) return 0;
                }
            }
        vis[u]=0;
    }
    return 1;
}
void add(int u, int v, int w) {
    to[++cnt]=v;wei[cnt]=w;next[cnt]=head[u];head[u]=cnt;
}
int main() {
    char ch[5];
    int i,u,v,w;
    while(scanf("%d%d",&n,&m)!=EOF) {
        cnt=0;
        memset(head,0,sizeof head);
        FOR(i,1,m) {
            scanf("%s",ch);
            if(ch[0] == 'P') u=read(),v=read(),w=read(),add(u,v,-w),add(v,u,w);
            else u=read(),v=read(),add(u,v,-1);
        }
        FOR(i,1,n) add(0,i,0);
        printf(spfa(0)?"Reliable\n":"Unreliable\n");
    }
    return 0;
}
