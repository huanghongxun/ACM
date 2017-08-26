#include <cstdio>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const int MAX=10000;
const int INF=1000000000;
struct point {
    int a,b;
    double x,y;
}p[200];
double D;
double Dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int min(int a,int b){return (a==-1||b<a)?b:a;}

class Dinic
{
#define M 100005
#define INF 0x7fffffff
private:
    int start, end; //起点和终点
    int to[M], next[M], head[M], cnt; //邻接表
    int level[M],w[M]; //层次和图
    queue<int> que; 
    //核心代码从这里开始
    bool bfs() //构建层次图
    {
        memset(level,-1,sizeof(level));
        level[start]=0;
        que.push(start);
        while(!que.empty())
        {
            int sta=que.front();
            que.pop();
            for(int i=head[sta];i!=-1;i=next[i])
                if(w[i]>0&&level[to[i]]<0)
                {
                    level[to[i]]=level[sta]+1;
                    que.push(to[i]);
                }
        }
        return level[end]!=-1;
    }
    int find(int x,int low) //寻找增广路
    {
        int tmp=0,result=0;
        if(x==end) return low;
        for(int i=head[x];i!=-1&&result<low;i=next[i])
            if(w[i]>0&&level[to[i]]==level[x]+1)
            {
                tmp=find(to[i],min(w[i],low-result));
                w[i]-=tmp;
                w[i^1]+=tmp;
                result+=tmp;
            }
        if(!result) level[x]=-1;
        return result;
    }
    //核心代码从这里结束
public:
    Dinic() //构造函数
    {
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
    }
    void init(int start, int end) //再用这个规定起点和终点
    {
        this->start = start;
        this->end = end;
    }
    void add(int a,int b,int flow) //先用这个构建图
    {
        to[cnt]=b,next[cnt]=head[a],w[cnt]=flow,head[a]=cnt++; //反向边
        to[cnt]=a,next[cnt]=head[b],w[cnt]=0,head[b]=cnt++; //正向边
    }
    int dinic() //最后用这个计算网络流
    {
        int ans=0,tmp;
        while(bfs()) ans+=find(start,INF);
        return ans;
    }
    void returnFirst() {
        for(int j=0;j<cnt;j+=2) w[j]+=w[j^1],w[j^1]=0; //每次流完之后恢复原图
    }
};

int main()
{
     int n,i,a,b,j,t;
     scanf("%d",&t);
     while(t--)
     {
         int sum=0;
         Dinic dinic;
         int s=0,t=n+1;
         scanf("%d%lf",&n,&D);
         for(i=1;i<=n;i++)
         {
             scanf("%lf%lf%d%d",&p[i].x,&p[i].y,&p[i].a,&p[i].b);
             sum+=p[i].a;
             dinic.add(s,i,p[i].a);
             dinic.add(i,i+n,p[i].b);
         }
         for(i=1;i<=n;i++)
         {
             for(j=i+1;j<=n;j++)
             {
                 if(Dis(p[i],p[j])<D)
                 {
                        dinic.add(n+i,j,INF);
                        dinic.add(n+j,i,INF);
                 }
             }
         }
         int flag=0;
         for(i=1;i<=n;i++)
         {
            dinic.init(s,i);
             if(dinic.dinic()==sum)
             {
                 printf("%d ",i-1);
                 flag=1;
             }
             dinic.returnFirst();
         }
         if(!flag) printf("-1\n");
         else printf("\n");
     }
}