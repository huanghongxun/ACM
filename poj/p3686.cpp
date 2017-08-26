#include <cstring>
#include <cstdio>
#include <algorithm>
#define nMax 405
#define eMax 1500
#define inf 0x7fffffff
using namespace std;
struct{
    int st, ed, w;
} inl[nMax];
struct{
    int v, cap, cost, next, re;    //  re记录逆边的下标.
} edge[eMax];
int n, m, ans, s, t;
int k, edgeHead[nMax];
int mp[nMax][nMax];
int que[nMax], pre[nMax], dis[nMax];
bool vis[nMax];
int hash[100005];
void addEdge(int u, int v, int ca, int co)
{
    edge[k].v = v;
    edge[k].cap = ca;
    edge[k].cost = co;
    edge[k].next = edgeHead[u];
    edge[k].re = k + 1;
    edgeHead[u] = k ++;
    edge[k].v = u;
    edge[k].cap = 0;
    edge[k].cost = -co;
    edge[k].next = edgeHead[v];
    edge[k].re = k - 1;
    edgeHead[v] = k ++;
}
bool spfa()
{
    int i, head = 0, tail = 1;
    for(i = 0; i <= t; i ++){
        dis[i] = inf;
        vis[i] = false;
    }
    dis[s] = 0;
    que[s] = 0;
    vis[s] = true;
    que[head] = s;
    while(tail > head)
    {
        int u = que[head ++];
        for(i = edgeHead[u]; i != -1; i = edge[i].next){
            int v = edge[i].v;
            if(edge[i].cap && dis[v] > dis[u] + edge[i].cost){
                dis[v] = dis[u] + edge[i].cost;
                pre[v] = i;
                if(!vis[v]){
                    vis[v] = true;
                    que[tail ++] = v;
                }
            }
        }
        vis[u] = false;
    }
    if(dis[t] == inf) return false;
    return true;
}

void end(){
    int u, p, sum = inf;
    for(u = n; u != -1; u = edge[edge[p].re].v)
    {
        p = pre[u];
        sum = min(sum, edge[p].cap);
    }
    for(u = n; u != -1; u = edge[edge[p].re].v)
    {
        p = pre[u];
        edge[p].cap -= sum;
        edge[edge[p].re].cap += sum;
        ans += sum * edge[p].cost;     //  cost记录的为单位流量费用,必须得乘以流量.
    }
}
int main(){
    int t, i;
    scanf("%d", &t);
    while(t --){
        scanf("%d%d",&n,&m);
        memset(edgeHead, -1, sizeof(edgeHead));
        s=0;
        t=n+n*m+1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&mp[i][j]);
        for(int i=1;i<=n;i++)
            addEdge(s,i,1,0);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<=n;k++)
                {
                    addEdge(i,n+(j-1)*n+k,1,mp[i][j]*k);
                }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                addEdge(n+(i-1)*n+j,t,1,0);
            }
        ans = 0;
        while(spfa()) end();
        printf("%.6lf\n", ans*1.0/n);
    }
    return 0;
}