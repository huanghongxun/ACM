#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <queue>  
#include <map>  
using namespace std; 
#define Max 2500  
#define mem(a,b) memset(a,b,sizeof(a))  
int N,M,C; 
#define inf 1 << 30  
#include <cstring>  
#include <string>  
 
struct kdq 
{ 
    int s , e , l ,next ; 
} ed[Max * 100] ; 
struct kdq1 
{ 
    int s ,e ,l ; 
} e[40005] ; 
int head[205] ,num ; 
int S,T ; 
void add(int s ,int e ,int l ) 
{ 
    ed[num].s = s ; 
    ed[num].e = e ; 
    ed[num].l = l ; 
    ed[num].next = head[s] ; 
    head[s] = num ++ ; 
 
    ed[num].s = e ; 
    ed[num].e = s ; 
    ed[num].l = 0 ; 
    ed[num].next = head[e] ; 
    head[e] = num ++ ; 
 
} 
 
void init() 
{ 
    memset(head,-1,sizeof(int) * (T + 1)) ; 
    num = 0 ; 
} 
int deep[205] ; 
int qe[Max * 100] ; 
int dinic_bfs() 
{ 
    memset(deep,-1,sizeof(int) * (T + 1)) ; 
    deep[S] = 0 ; 
    int h = 0 ,t = 0 ; 
    qe[h ++ ] = S ; 
    while(h > t) 
    { 
        int tt = qe[t ++ ] ; 
        for (int i = head[tt] ; ~i ; i = ed[i].next ) 
        { 
            int e = ed[i].e ; 
            int l = ed[i].l ; 
            if(deep[e] == -1 && l > 0 ) 
            { 
                deep[e] = deep[tt] + 1 ; 
                qe[h ++ ] = e ; 
            } 
        } 
    } 
    return deep[T] != -1 ; 
} 
 
int dinic_dfs(int now ,int f ) 
{ 
    if(now == T)return f ; 
    int flow = 0 ; 
    for (int i = head[now] ; ~i ; i = ed[i].next ) 
    { 
        int e = ed[i].e ; 
        int l = ed[i].l ; 
        if(deep[e] == deep[now] + 1 && l > 0 && (f - flow))//f - flow > 0 加了这个优化就A了。否则T到死  
        { 
            int mm = min(l,f - flow) ; 
            int nn = dinic_dfs(e , mm) ; 
            flow += nn ; 
            ed[i].l -= nn ; 
            ed[i ^ 1].l += nn ; 
        } 
    } 
    if(!flow )deep[now] = -2 ; 
    return flow ; 
} 
int dinic() 
{ 
    int flow = 0 ; 
    int f ; 
    while(dinic_bfs()) 
    { 
        flow += dinic_dfs(S,inf) ; 
    } 
    return flow ; 
} 
void build_Map(int mid) 
{ 
    init() ; 
    for (int i = 1 ; i <= C ; i ++ ) 
    { 
        if(e[i].l <= mid) 
        { 
            add(e[i].s ,e[i].e ,1) ; 
            add(e[i].e ,e[i].s ,1) ; 
        } 
    } 
    add(S,1,inf) ; 
    add(N,T,inf) ; 
} 
int main() 
{ 
    scanf("%d%d%d",&N,&C,&M) ; 
    int l = inf ,r = -1 ; 
    S = 0 ,T = N + 1 ; 
    for (int i = 1 ; i <= C ; i ++ ) 
    { 
        scanf("%d%d%d",&e[i].s,&e[i].e,&e[i].l) ; 
        l = min(l,e[i].l) ; 
        r = max(r,e[i].l) ; 
    } 
    int mid = l + r >> 1 ; 
    while(r > l) 
    { 
        mid = (l + r ) >> 1 ; 
        build_Map(mid) ; 
        int ans = dinic() ; 
        if(ans < M) l = mid + 1 ; 
        else r = mid ; 
    } 
    printf("%d\n",r) ; 
 
    return 0; 
} 