#include <cstdio>
#include <queue>
#define N 50005
#define M 1000005
#include <cstring>
#define INF 0x7fffffff
#define rep(i,j,k) for(i=j;i<k;i++)
using namespace std;
int map[205][205];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class Dinic {
public:
    int start, end;
    int from[M], to[M], next[M], head[M], cnt;
    int level[M],w[M];
    queue<int> que; 
    bool bfs() {
        memset(level,-1,sizeof(level));
        level[start]=0;
        que.push(start);
        while(!que.empty()) {
            int sta=que.front();
            que.pop();
            for(int i=head[sta];i!=-1;i=next[i])
                if(w[i]>0&&level[to[i]]<0) {
                    level[to[i]]=level[sta]+1;
                    que.push(to[i]);
                }
        }
        return level[end]!=-1;
    }
    int find(int x,int low) {
        int tmp=0,result=0;
        if(x==end) return low;
        for(int i=head[x];i!=-1&&result<low;i=next[i])
            if(w[i]>0&&level[to[i]]==level[x]+1) {
                tmp=find(to[i],min(w[i],low-result));
                w[i]-=tmp;
                w[i^1]+=tmp;
                result+=tmp;
            }
        if(!result) level[x]=-1;
        return result;
    }
public:
    void init(int start, int end) {
        this->start = start;
        this->end = end;
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
        cnt = 0;
    }
    void add(int a,int b,int flow) {
        from[cnt]=a,to[cnt]=b,next[cnt]=head[a],w[cnt]=flow,head[a]=cnt++;
        from[cnt]=b,to[cnt]=a,next[cnt]=head[b],w[cnt]=0,head[b]=cnt++;
    }
    int dinic() {
        int ans=0,tmp;
        while(bfs()) ans+=find(start,INF);
        return ans;
    }
} g;

int main() {
    int n,m,i,j,k;
    int tt=0;
    while(scanf("%d%d",&n,&m)!=EOF) {
        int i,j;
        rep(i,0,n) rep(j,0,m) scanf("%d",&map[i][j]);
        int s=n*m, t=n*m+1;
        g.init(s, t);
        rep(i,0,n) rep(j,0,m) {
            rep(k,0,4) {
                int tx=i+dx[k], ty=j+dy[k];
                if(tx<0||tx>=n||ty<0||ty>=m) continue;
                g.add(i*m+j,tx*m+ty,1);
            }
            if(map[i][j]==1) g.add(i*m+j,t,INF);
            if(map[i][j]==2) g.add(s,i*m+j,INF);
        }
        printf("Case %d:\n", ++tt);
        printf("%d\n", g.dinic());
    }
    return 0;
}
