#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x7fffffff
#define ll long long
#define P 256
#define N 1024
#define M 524288
using namespace std;
int n,m;
int c[P],a[P][P],s[P],t[P][16],w[P][16];
struct DinicMinCost {
    int to[M],p[M],c[M],w[M],h[N],q[N*8],s,t,cnt;
    ll dis[N],ans;
    bool vis[N];
    void add(int i,int j,int k,int l) {
        to[cnt]=j;c[cnt]=l;w[cnt]=k;p[cnt]=h[i];h[i]=cnt++;
        to[cnt]=i;c[cnt]=-l;w[cnt]=0;p[cnt]=h[j];h[j]=cnt++;
    }
    bool spfa() {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<N;i++)dis[i]=inf;
        int f=0,r=0;
        dis[s]=0;vis[s]=1;q[r++]=s;
        while(f<r) {
            int now=q[f++];
            for(int i=h[now];i!=-1;i=p[i])
                if(w[i]&&dis[to[i]]>dis[now]+c[i]) {
                    dis[to[i]]=dis[now]+c[i];
                    if(!vis[to[i]]) {
                        vis[to[i]]=1;
                        q[r++]=to[i];
                    }
                }
            vis[now]=0;    
        }
        if(dis[t]==inf)return 0;
        return 1;
    }
    ll dfs(int x,int low) {
        vis[x] = 1;
        if(x==t) { vis[t] = 1; return low; }
        int result = 0, tmp;
        for(int i=h[x];i!=-1&&result<low;i=p[i])
            if(!vis[to[i]]&&w[i]&&dis[x]+c[i]==dis[to[i]]) {
                tmp=dfs(to[i],min(w[i],low-result));
                w[i]-=tmp;w[i^1]+=tmp;
                ans+=tmp*c[i];
                result+=tmp;
            }
        return result;
    }
    ll run() {
        ans = 0;
        while(spfa()) {
            vis[t] = 1;
            while(vis[t]) {
                memset(vis,0,sizeof(vis));
                dfs(s,inf);
            }
        }
        return ans;
    }
    void init(int S, int T) {
        s=S;t=T;cnt = 0;
        memset(h,-1,sizeof(h));
    }
} g;
void build() {
    g.init(0,1001);
    for(int i=1;i<=n;i++)
        g.add(0,i,c[i],0);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]) g.add(j,n+i,inf,0);
    for(int i=1;i<=m;i++)
       for(int j=1;j<=s[i]+1;j++)
          g.add(n+i,1001,t[i][j]-t[i][j-1],w[i][j]);
} 
int main() {
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=m;i++) {
        scanf("%d",&s[i]);
        for(int j=1;j<=s[i];j++) scanf("%d",&t[i][j]);
        t[i][s[i]+1]=inf;
        for(int j=1;j<=s[i]+1;j++) scanf("%d",&w[i][j]);
    }
    build();
    printf("%lld",g.run());
    return 0; 
}