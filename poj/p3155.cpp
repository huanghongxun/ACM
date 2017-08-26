#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 1e10
#define eps 1e-7
#define N 2005
#define M 20005
int d[N],x[N],y[N];
struct Dinic {
    int s, t;
    int fr[M], to[M], p[M], h[M], cnt, l[M], q[N*8], cut[M]; 
    double w[M];
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
    double find(int x, double low) {
        double tmp=0,result=0;
        if(x==t) return low;
        for(int i=h[x];i!=-1&&result<low;i=p[i])
            if(w[i]>eps&&l[to[i]]==l[x]+1) {
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
    void add(int a,int b,double flow) {
        fr[cnt]=a,to[cnt]=b,p[cnt]=h[a],w[cnt]=flow,h[a]=cnt++;
        fr[cnt]=b,to[cnt]=a,p[cnt]=h[b],w[cnt]=0,h[b]=cnt++;
    }
    double dinic() {
        double ans=0;
        while(bfs()) ans+=find(s,inf);
        return ans;
    }
    void findCut() {
		int f = 0, r = 0;
		memset(l, 0, sizeof(l));
		l[s] = 1; q[r++] = s;
	    while (f < r) {
	    	int u = q[f++];
		    for (int i = h[u]; i >= 0; i = p[i])
		    	if(w[i] > 0 && !l[to[i]]) q[r++] = to[i], l[to[i]] = 1;
		}
		for (int i=0;i<cnt;i+=2)
			if (l[fr[i]] ^ l[to[i]]) cut[i] = 1;
	}
	void printAns() {
		int ans = 0;
		memset(l, 0, sizeof(l));
		for(int i=h[s];i>=0;i=p[i])
			if(cut[i]) ans++, l[to[i]]=1;
	    printf("%d\n", ans);
	    for (int i=1;i<=t;++i) if (l[i]) printf("%d\n",i);
	}
} graph;
int s, t, n, m;
bool check(double g) {
    graph.init(s, t);
    for (int i=1;i<=n;++i)
        graph.add(s, i, m),
        graph.add(i, t, m+2*g-graph.d[i]);
    for (int i=1;i<=m;++i) {
        graph.add(x[i],y[i],inf);
        graph.add(y[i],x[i],inf);
	}
    return (m*n-graph.dinic())/2>eps;
}
int main() {
    scanf("%d%d",&n,&m);
    if (!m) return printf("1\n1\n"),0;
    for (int i=1;i<=m;++i)
        scanf("%d%d",x+i,y+i), d[x[i]]++, d[y[i]]++;
    s=n+m+1; t=s+1;
    int bi=132;
    double l=1/(double)n,r=m,mid;
    for (mid=(l+r)/2;(r-l)*n*n>1;mid=(l+r)/2)
	    if (check(mid)) l=mid;
	    else r=mid;
    check(l);
	graph.findCut();
	graph.printAns();
    return 0;
}

