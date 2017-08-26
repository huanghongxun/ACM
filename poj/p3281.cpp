#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <algorithm>  
  
using namespace std;  
  
const int maxn = 500;  
const int maxm = 21000;  
const int oo = 1 << 30;  
  
int idx;  
class Dinic
{
private:
    int start, end; //起点和终点
    int to[maxm], next[maxm], head[maxn], cnt; //邻接表
    int level[maxn],w[maxm]; //层次和图
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
        while(bfs()) ans+=find(start,oo);
        return ans;
    }
};
  
int N, F, D;  
int main()  
{  
    while (scanf("%d %d %d", &N, &F, &D) != EOF)  
    {  
        idx = 0;  
        int a, b, f, d;  
        Dinic dinic;
        for (int i = 1; i <= N; ++i)  
        {  
            scanf("%d %d", &a, &b);  
            while (a--)  
            {  
                scanf("%d", &f);  
                dinic.add(f, F + i, 1);  
            }  
            while (b--)  
            {  
                scanf("%d", &d);  
                dinic.add(F + N + i, F + N + N + d, 1);  
            }  
  
        }  
        int source = 0, sink = N + N + F + D + 1;  
        int n = sink + 1;  
        for (int i = 1; i <= F; ++i)  
            dinic.add(source, i, 1);  
        for (int i = 1; i <= N; ++i)  
            dinic.add(F + i, F + N + i, 1);  
        for (int i = 1; i <= D; ++i)  
            dinic.add(F + N + N + i, sink, 1);  
        dinic.init(source, sink);
        printf("%d\n", dinic.dinic());  
    }  
    return 0;  
}  