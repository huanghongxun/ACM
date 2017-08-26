#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x7fffffff;
const int N = 65536;
const int M = 65536;

struct Dinic {
    int s, t;
    int to[M], p[M], h[M], cnt, l[M], w[M], q[N*8];
    bool bfs() {
        memset(l,-1,sizeof(l));
        l[s]=0;
        int f = 0, r = 0;
        q[r++] = s;
        while(f < r) {
            int u = q[f++];
            for(int i=h[u];i!=-1;i=p[i])
                if(w[i]>0&&l[to[i]]<0) {
                    l[to[i]]=l[u]+1;
                    q[r++]=to[i];
                }
        }
        return l[t]!=-1;
    }
    int find(int x,int low) {
        int tmp=0,result=0;
        if(x==t) return low;
        for(int i=h[x];i!=-1&&result<low;i=p[i])
            if(w[i]>0&&l[to[i]]==l[x]+1) {
                tmp=find(to[i],min(w[i],low-result));
                w[i]-=tmp; w[i^1]+=tmp;
                result+=tmp;
            }
        if(!result) l[x]=-1;
        return result;
    }
    void init(int start, int end) {
        this->s= start;
        this->t= end;
        memset(h,-1,sizeof(h));
        cnt = 0;
    }
    void add(int a,int b,int flow) {
        to[cnt]=b,p[cnt]=h[a],w[cnt]=flow,h[a]=cnt++;
        to[cnt]=a,p[cnt]=h[b],w[cnt]=0,h[b]=cnt++;
    }
    int dinic() {
        int ans=0;
        while(bfs()) ans+=find(s,inf);
        return ans;
    }
} g;

int main() {
    int x,y,z,sum=0,n,m;
    scanf("%d%d",&n,&m);
    int S=0,T=n+m+1;
    g.init(S,T);
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        g.add(S,i,x);
    }
    for (int i=1;i<=m;i++) {
        scanf("%d%d%d",&x,&y,&z);
        g.add(n+i,T,z);
        g.add(x,n+i,inf);
        g.add(y,n+i,inf);
        sum+=z;
    }
    printf("%d", sum-g.dinic());
    return 0;
}