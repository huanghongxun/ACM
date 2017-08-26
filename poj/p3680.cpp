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
int n, m, ans;
int k, edgeHead[nMax];
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
bool spfa() //  源点为0,汇点为n.
{
    int i, head = 0, tail = 1;
    for(i = 0; i <= n; i ++){
        dis[i] = inf;
        vis[i] = false;
    }
    dis[0] = 0;
    que[0] = 0;
    vis[0] = true;
    while(tail > head) //  这里最好用队列,有广搜的意思,堆栈像深搜.
    {
        int u = que[head ++];
        for(i = edgeHead[u]; i != 0; i = edge[i].next){
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
    if(dis[n] == inf) return false;
    return true;
}

void end(){
    int u, p, sum = inf;
    for(u = n; u != 0; u = edge[edge[p].re].v)
    {
        p = pre[u];
        sum = min(sum, edge[p].cap);
    }
    for(u = n; u != 0; u = edge[edge[p].re].v)
    {
        p = pre[u];
        edge[p].cap -= sum;
        edge[edge[p].re].cap += sum;
        ans += sum * edge[p].cost;     //  cost记录的为单位流量费用,必须得乘以流量.
    }
}
int main(){
    int t, i, N, K;
    scanf("%d", &t);
    while(t --){
        memset(edgeHead, -1, sizeof(edgeHead));
        memset(hash, 0, sizeof(hash));
        scanf("%d%d", &N, &K);
        for(i = 0; i < N; i ++){
            scanf("%d%d%d", &inl[i].st, &inl[i].ed, &inl[i].w);
            hash[inl[i].st] = hash[inl[i].ed] = 1;
        }
        for(k = 1, i = 0; i <= 100000; i ++)     //  由于100000不大，所以我用hash离散化。
            if(hash[i] == 1)
                hash[i] = k ++;
        for(i = 0; i < N; i ++){                 //  线段的端点值，改为离散后的下标号。
            inl[i].st = hash[inl[i].st];
            inl[i].ed = hash[inl[i].ed];
        }
        n = k; k = 0;
        for(i = 0; i < n; i ++)                  //  建图。
            addEdge(i, i+1, K, 0);
        for(i = 0; i < N; i ++)
            addEdge(inl[i].st, inl[i].ed, 1, inl[i].w);
        ans = 0;
        while(spfa()) end();
        printf("%d\n", ans);
    }
    return 0;
}