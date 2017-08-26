#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define eps 1e-5
#define N 8192
#define M 65536
#define INF 100000007
using namespace std;
class ZKW {
protected:
    int start, end, ans; //起点和终点
    int to[M], next[M], head[N], cnt; //邻接表
	int dis[N], w[M], c[M], vis[N]; //层次和图
	int q[N*8];
    //核心代码从这里开始
    bool spfa() { //构建层次图
        memset(dis,-1,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[end]=0; vis[end]=1;
        int f=0,r=0; q[r++]=end;
        while(f<r) {
            int sta=q[f++];
            for(int i=head[sta];i!=-1;i=next[i])
                if(w[i^1]>0&&dis[to[i]]<dis[sta]+c[i^1]) {
                    dis[to[i]]=dis[sta]+c[i^1];
                    if(!vis[to[i]]) { vis[to[i]] = 1; q[r++]=to[i]; }
                }
            vis[sta]=0;
        }
        return dis[start]!=-1;
    }
    int find(int x,int low) { //寻找增广路
        int tmp=0,result=0; vis[x]=1;
        if(x==end) return low;
        for(int i=head[x];i!=-1&&result<low;i=next[i])
            if(w[i]>0&&dis[to[i]]==dis[x]-c[i]&&!vis[to[i]]) {
                tmp=find(to[i],min(w[i],low-result));
                w[i]-=tmp; w[i^1]+=tmp;
                ans+=tmp*c[i];
                result+=tmp;
            }
        return result;
    }
    //核心代码从这里结束
public:
    void init(int start, int end) { //再用这个规定起点和终点
        this->start = start;
        this->end = end;
        memset(head,-1,sizeof(head));
        memset(next,-1,sizeof(next));
        cnt = 0;
    }
    void add(int a,int b,int flow,int cost) { //先用这个构建图
        to[cnt]=b,next[cnt]=head[a],w[cnt]=flow,c[cnt]=cost,head[a]=cnt++; //正向边
        to[cnt]=a,next[cnt]=head[b],w[cnt]=0,c[cnt]=-cost,head[b]=cnt++; //反向边
    }
    int zkw() { //最后用这个计算网络流
        ans=0;
        while(spfa()) {
        	vis[end]=1;
        	while(vis[end]) {
	        	memset(vis,0,sizeof(vis));
				find(start,INF);
			}
		}
        return ans;
    }
} g;
int main()
{
    int w, nt, k;
    while(scanf("%d%d", &nt, &k) != EOF)
    {
        int src = nt * nt * 2 + 1;
        int des = nt * nt * 2 + 2;
        int n = des;
        g.init(src, des);
        for(int i = 1; i <= nt; i++)
            for(int j = 1; j <= nt; j++) {
                scanf("%d", &w);
                int id = (i - 1) * nt + j;
                g.add(id, id + nt * nt, 1, w);
                g.add(id, id + nt * nt, k, 0);
                if(i < nt) g.add(id + nt * nt, id + nt, k, 0);
                if(j < nt) g.add(id + nt * nt, id + 1, k, 0);
            }
        g.add(src, 1, k, 0);
        g.add(nt * nt * 2, des, k, 0);
        printf("%d\n", g.zkw());
    }
    return 0;
}
