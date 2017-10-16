#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//by mars_ch
struct data
{
    int u,v;
}e[100005];
int n,tot,ans;
int a[10],b[10];
int last[10005],s[10];
void dfs(int u, int v)
{
    if(u>=n)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i] != s[i]) return;
        }
        ans++;

        return;
    }
    //int u=e[x].u,v=e[x].v;
    //if((last[u]-x+1)*3+a[u]<s[u]) return;  //都赢也不可以  
    //if((last[v]-x+1)*3+a[v]<s[v]) return;
    if(v == n)
    {
        if(a[u]+3 == s[u])
        {
            a[u]+=3;
            if(a[v]<=s[v]) dfs(u+1,u+2);
            a[u]-=3;
        }
        else if(a[u]+1==s[u])
        {
            a[u]+=1,a[v]+=1;
            if(a[v] <= s[v]) dfs(u+1,u+2);
            a[u]-=1,a[v]-=1;
        }
        else if(a[u]==s[u])
        {
            a[v]+=3;
            if(a[v] <= s[v]) dfs(u+1,u+2);
            a[v]-=3;
        }
        return;
    }
    if(a[u]+3<=s[u])
    {
        a[u]+=3;
        dfs(u,v+1);
        a[u]-=3;
    }
    if(a[u]+1<=s[u] && a[v]+1<=s[v])
    {
        a[u]+=1,a[v]+=1;
        dfs(u,v+1);
        a[u]-=1,a[v]-=1;
    }
    if(a[u]<=s[u] && a[v]+3<=s[v])
    {
        a[v]+=3;
        dfs(u,v+1);
        a[v]-=3;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            e[++tot].u=i,e[tot].v=j;
        }
        last[i]=tot;   //每队最后比赛的场 
    } 
    dfs(1,2);
    printf("%d\n",ans);
    return 0;
}