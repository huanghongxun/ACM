#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 300000000
#define M 1002
#define N 102
int s,t;
int i,j;
int n;
int cus[N][N];

class Dinic
{
private:
    int start, end; //起点和终点
    int level[M];
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
            for(int i=1;i<=n;i++)
                if(cus[sta][i]>0&&level[i]<0)
                {
                    level[i]=level[sta]+1;
                    que.push(i);
                }
        }
        return level[end]!=-1;
    }
    int find(int x,int low) //寻找增广路
    {
        int tmp=0,result=0;
        if(x==end) return low;
        for(int i=1;i<=n&&result<low;i++)
            if(cus[x][i]>0&&level[i]==level[x]+1)
            {
                tmp=find(i,min(cus[x][i],low-result));
                cus[x][i]-=tmp;
                cus[i][x]+=tmp;
                result+=tmp;
            }
        if(!result) level[x]=-1;
        return result;
    }
    //核心代码从这里结束
public:
    Dinic() //构造函数
    {
    }
    void init(int start, int end) //再用这个规定起点和终点
    {
        this->start = start;
        this->end = end;
    }
    int dinic() //最后用这个计算网络流
    {
        int ans=0,tmp;
        while(bfs()) ans+=find(start,INF);
        return ans;
    }
};

int main()
{
    int m;
    int num,k;
    int house[M],last[M];
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        Dinic dinic;
        memset(last,0,sizeof(last));
        memset(cus,0,sizeof(cus));
        s=0;t=n+1;
        dinic.init(s,t);
        for(i=1;i<=m;i++)
            scanf("%d",&house[i]);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num);
            for(j=0;j<num;j++)
            {
                scanf("%d",&k);
                if(last[k]==0)
                   cus[s][i]=cus[s][i]+house[k];
                else
                   cus[last[k]][i]=INF;
                last[k]=i;
            }
            scanf("%d",&cus[i][t]);
        }
        printf("%d\n", dinic.dinic());
    }
}