#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define inf 0x7ffffff
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define rep(i,j,k) for(i=j;i<k;i++)
using namespace std;

const int N=22222;
const int M=1000000;

class Dinic {
protected:
    int start, end; //起点和终点
    int to[M], next[M], head[N], cur[N], cnt; //邻接表
    int level[M], w[M],q[M*5]; //层次和图
    //核心代码从这里开始
    bool bfs() { //构建层次图
        int f=0,r=0;
        memset(level,-1,sizeof(level));
        level[start]=0;
        q[r++]=start;
        while(f<r) {
            int sta=q[f++];
            for(int i=head[sta];i!=-1;i=next[i])
                if(w[i]>0&&level[to[i]]<0) {
                    level[to[i]]=level[sta]+1;
                    q[r++]=to[i];
                }
        }
        return level[end]!=-1;
    }
    int find(int x,int low) { //寻找增广路
        int tmp=0,result=0;
        if(x==end) return low;
        for(int i=cur[x];i!=-1&&result<low;i=next[i])
            if(w[i]>0&&level[to[i]]==level[x]+1) {
                tmp=find(to[i],min(w[i],low-result));
                w[i]-=tmp; w[i^1]+=tmp;
                if(w[i]) cur[x]=i;
                result+=tmp;
            }
        if(!result) level[x]=-1;
        return result;
    }
    //核心代码从这里结束
public:
    Dinic() { //构造函数
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
    }
    void init(int start, int end) { //再用这个规定起点和终点
        this->start = start;
        this->end = end;
    }
    void add(int a,int b,int flow) { //先用这个构建图
        to[cnt]=b,next[cnt]=head[a],w[cnt]=flow,head[a]=cnt++; //反向边
        to[cnt]=a,next[cnt]=head[b],w[cnt]=0,head[b]=cnt++; //正向边
    }
    int dinic() { //最后用这个计算网络流
        int ans=0;
        while(bfs()) {
            for(int i=0; i<=end; i++) cur[i]=head[i];
            ans+=find(start,inf);
        }
        return ans;
    }
} g;

int in[N];

int main() {
    int n, m, i, x, y, j;
    scanf("%d", &n);
    FOR(i,1,n) {
        scanf("%d", &x);
        FOR(j,1,x) {
            scanf("%d", &y);
            g.add(i,n+2*m-1,inf);
            g.add(n+2*m,y,inf);
        }
    }
    int s=n+2*m+1;int t=s+1;
    g.init(0,t);
    FOR(i,1,m) {
        g.add(n+2*i-1,n+2*i,inf);
        in[n+2*i-1]--;
        in[n+2*i]++;
    }
    FOR(i,1,n) g.add(s,i,inf);
    FOR(i,n+1,n+2*m)
        if(in[i]>0) g.add(0,i,in[i]);
        else g.add(i,t,-in[i]);
    for(i=1;;i++) {
        g.add(0,s,1);
        if(g.dinic()==m) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}