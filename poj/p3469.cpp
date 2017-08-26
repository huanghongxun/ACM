#include <stdio.h>
#include <queue>
#include <memory.h>
using namespace std;
class Dinic
{
#define M 200005
#define INF 0x7fffffff
private:
    int start, end; //起点和终点
    int to[M], next[M], head[M], cnt; //邻接表
    int level[M],w[M]; //层次和图
    //核心代码从这里开始
    bool bfs() //构建层次图
    {
		queue<int> q;
        memset(level,-1,sizeof(level));
        level[start]=0;
        q.push(start);
        while(!q.empty())
        {
            int sta=q.front();
            q.pop();
            for(int i=head[sta];i!=-1;i=next[i])
                if(w[i]>0&&level[to[i]]<0)
                {
                    level[to[i]]=level[sta]+1;
                    q.push(to[i]);
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
    }
    void init(int start, int end) //再用这个规定起点和终点
    {
        this->start = start;
        this->end = end;
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
		cnt = 0;
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
};
int main(){
	int n,m;
    scanf("%d %d",&n,&m);
	int s=0,t=n+1;
    int a,b,c;
	Dinic dinic;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
		dinic.add(s, i, a);
		dinic.add(i, t, b);
    }
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
		dinic.add(a,b,c);
    }
    int ans=dinic.dinic();
    printf("%d\n",ans);
    return 0;
}