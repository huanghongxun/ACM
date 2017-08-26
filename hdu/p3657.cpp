#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 101000
#define M 500100
#define INF 0x3f3f3f3f

int map[110][110];

struct Dinic {
    int s, t; //起点和终点
    int to[M], p[M], h[M], cnt, l[M],w[M]; //邻接表
    int q[N*8]; 
    //核心代码从这里开始
    bool bfs() { //构建层次图
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
    int find(int x,int low) { //寻找增广路
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
    //核心代码从这里结束
    void init(int start, int end) { //再用这个规定起点和终点
        this->s= start;
        this->t= end;
        memset(h,-1,sizeof(h));
        cnt = 0;
    }
    void add(int a,int b,int flow) { //先用这个构建图
        to[cnt]=b,p[cnt]=h[a],w[cnt]=flow,h[a]=cnt++; //反向边
        to[cnt]=a,p[cnt]=h[b],w[cnt]=0,h[b]=cnt++; //正向边
    }
    int dinic() { //最后用这个计算网络流
        int ans=0,tmp;
        while(bfs()) ans+=find(s,INF);
        return ans;
    }
} g;

int main(){
    int n, m, k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        int src=0, des=n*m+1;
        g.init(src,des);
        int sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
                sum+=map[i][j];
            }
        int x,y;
        while(k--){
            scanf("%d%d",&x,&y);
            if((x+y)%2==0)
                g.add(src,(x-1)*m+y,INF);
            else
                g.add((x-1)*m+y,des,INF);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                int tmp=(i-1)*m+j;
                if((i+j)%2==0)
                    g.add(src,tmp,map[i][j]);
                else
                    g.add(tmp,des,map[i][j]);
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if((i+j)%2==0){
                    int tmp=(i-1)*m+j;
                    if(i>1) g.add(tmp,tmp-m,2*(map[i][j]&map[i-1][j]));
                    if(i<n) g.add(tmp,tmp+m,2*(map[i][j]&map[i+1][j]));
                    if(j>1) g.add(tmp,tmp-1,2*(map[i][j]&map[i][j-1]));
                    if(j<m) g.add(tmp,tmp+1,2*(map[i][j]&map[i][j+1]));
                }
        printf("%d\n",sum-g.dinic());
    }
    return 0;
}
