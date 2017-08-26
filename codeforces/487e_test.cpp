#include <set>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define M 100100  
#define INF 0x3f3f3f3f  
using namespace std;  
struct BCC{  
    multiset<int>s;  
    int value;  
    inline void Insert(int x)  
    {  
        s.insert(x);  
        value=*s.begin();  
    }  
    inline void Modify(int x,int y)  
    {  
        s.erase( s.find(x) );  
        s.insert(y);  
        value=*s.begin();  
    }  
}BCCs[M<<1];  
namespace ZKW_Segtree{  
    int tree[263000<<1]={INF};  
    int q;  
    void Build_Tree(int a[],int n)  
    {  
        int i;  
        for(q=1;q<=n+1;q<<=1);  
        for(i=1;i<=n;i++)  
            tree[q+i]=a[i];  
        for(i=q-1;i;i--)  
            tree[i]=min(tree[i<<1],tree[i<<1|1]);  
    }  
    void Modify(int x,int y)  
    {  
        tree[x+=q]=y;  
        while(x>>=1)  
            tree[x]=min(tree[x<<1],tree[x<<1|1]);  
    }  
    int Get_Ans(int x,int y)  
    {  
        int re=INF;  
        for(x+=q-1,y+=q+1;x^y^1;x>>=1,y>>=1)  
        {  
            if(~x&1) re=min(re,tree[x^1]);  
            if( y&1) re=min(re,tree[y^1]);  
        }  
        return re;  
    }  
}  
int n,m,q,cnt;  
int a[M],belong[M];  
bool v[M];  
namespace New_Map{  
    struct abcd{  
        int to,next;  
    }table[M<<2];  
    int head[M<<1],tot;  
    int fa[M<<1],son[M<<1],dpt[M<<1],size[M<<1],top[M<<1],pos[M<<1],posf[M<<1],T;  
    void Add(int x,int y)  
    {  
        table[++tot].to=y;  
        table[tot].next=head[x];  
        head[x]=tot;  
    }  
    void DFS1(int x)  
    {  
        int i;  
        size[x]=1;  
        dpt[x]=dpt[fa[x]]+1;  
        for(i=head[x];i;i=table[i].next)  
            if(table[i].to!=fa[x])  
            {  
                fa[table[i].to]=x;  
                DFS1(table[i].to);  
                size[x]+=size[table[i].to];  
                if(size[table[i].to]>size[son[x]])  
                    son[x]=table[i].to;  
            }  
    }  
    void DFS2(int x,int t)  
    {
        posf[pos[x]=++T]=BCCs[x].value;  
        top[x]=t;
        if(son[x])  
            DFS2(son[x],t);  
        for(int i=head[x];i;i=table[i].next)  
            if(table[i].to!=fa[x]&&table[i].to!=son[x])  
                DFS2(table[i].to,table[i].to);  
    }  
    int LCA(int x,int y)  
    {  
        int fx=top[x],fy=top[y];  
        while(fx!=fy)  
        {  
            if(dpt[fx]<dpt[fy])  
                swap(x,y),swap(fx,fy);  
            x=fa[fx];fx=top[x];  
        }  
        if(dpt[x]<dpt[y])  
            swap(x,y);  
        return y;  
    }  
    void Make_Graph()  
    {  
        int i;  
        memset(posf,0x3f,sizeof posf);  
        DFS1(n+1);DFS2(n+1,n+1);  
        ZKW_Segtree::Build_Tree(posf,T);  
    }  
    int Query(int x,int y)  
    {  
        int re,fx=top[x],fy=top[y],temp=LCA(x,y);  
        if(temp<=cnt) temp=fa[temp];re=a[temp-n];  
        while(fx!=fy)  
        {  
            if(dpt[fx]<dpt[fy])  
                swap(x,y),swap(fx,fy);  
            re=min(re,ZKW_Segtree::Get_Ans(pos[fx],pos[x]));  
            x=fa[fx];fx=top[x];  
        }  
        if(dpt[x]<dpt[y])  
            swap(x,y);  
        re=min(re,ZKW_Segtree::Get_Ans(pos[y],pos[x]));  
        return re;  
    }  
}  
namespace Ori_Map{  
    struct abcd{  
        int to,next;  
    }table[M<<1];  
    int head[M],tot;  
    void Add(int x,int y)  
    {  
        table[++tot].to=y;  
        table[tot].next=head[x];  
        head[x]=tot;  
    }  
    void Tarjan(int x)  
    {  
        static int stack[M],top;  
        static int dpt[M],low[M],T;  
        int i;  
        dpt[x]=low[x]=++T;  
        stack[++top]=x;  
        for(i=head[x];i;i=table[i].next)  
        {  
            if(dpt[table[i].to])  
                low[x]=min(low[x],dpt[table[i].to]);  
            else  
            {  
                Tarjan(table[i].to);  
                low[x]=min(low[x],low[table[i].to]);  
                if(dpt[x]==low[table[i].to])  
                {  
                    int t;++cnt;  
                    v[x]=1;  
                    do{  
                        t=stack[top--];  
                        belong[t]=cnt;  
                        if(v[t])  
                        {  
                            New_Map::Add(t+n,cnt);  
                            New_Map::Add(cnt,t+n);  
                        }  
                    }while(t!=table[i].to);  
                    New_Map::Add(x+n,cnt);  
                    New_Map::Add(cnt,x+n);  
                }  
            }  
        }  
    }  
    inline void Make_Graph()  
    {  
        int i;  
        Tarjan(1);  
        for(i=1;i<=n;i++)  
        {  
            if(i!=1)  
                BCCs[ belong[i] ].Insert(a[i]);  
            if(v[i]) BCCs[i+n].Insert(INF);  
        }  
        New_Map::Make_Graph();  
    }  
}  
int main()  
{  
      
    //freopen("30.in","r",stdin);  
    //freopen("30.out","w",stdout);  
      
    int i,x,y;  
    char p[10];  
    cin>>n>>m>>q;  
    for(i=1;i<=n;i++)  
        scanf("%d",&a[i]);  
    for(i=1;i<=m;i++)  
        scanf("%d%d",&x,&y),Ori_Map::Add(x,y),Ori_Map::Add(y,x);  
    Ori_Map::Make_Graph();  
    for(i=1;i<=q;i++)  
    {  
        scanf("%s%d%d",p,&x,&y);  
        if(p[0]=='C')  
        {  
            if(x!=1)  
            {  
                BCCs[belong[x]].Modify(a[x],y);  
                ZKW_Segtree::Modify(New_Map::pos[belong[x]],BCCs[belong[x]].value);  
            }  
            a[x]=y;  
        }  
        else  
        {  
            if(x==y)  
            {  
                printf("%d\n",a[x]);  
                continue;  
            }
            x=v[x]?x+n:belong[x];  
            y=v[y]?y+n:belong[y];  
            printf("%d\n", New_Map::Query(x,y) );  
        }  
    }  
    return 0;  
}  
