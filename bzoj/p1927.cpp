#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long 
#define inf 1000000000
using namespace std;
int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define N 2048
#define M 2097152
struct DinicMinCost {
    int to[M],p[M],c[M],w[M],h[N],q[N*8],s,t,cnt;
    int dis[N],ans;
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
    int dfs(int x,int low) {
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
    int run() {
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
int main() { 
    int n=read(),m=read(),T=2*n+1;
    g.init(0,T);
    for(int i=1;i<=n;i++)
    {
        int t=read();
        g.add(0,i,1,0);
        g.add(i+n,T,1,0);
        g.add(0,i+n,1,t);
    }
    for(int i=1;i<=m;i++) {
        int u=read(),v=read(),c=read();
        if(u>v)swap(u,v);
        g.add(u,v+n,1,c);
    }
    printf("%d",g.run());
    return 0; 
}