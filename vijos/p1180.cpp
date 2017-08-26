#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
int f[302][302],score[302],brother[302],child[302];
bool vis[302][302];
int n,k;
void dfs(int i,int j)
{
    if (vis[i][j]) return;
    vis[i][j]=true;
    if ((i==0)||(j==0)) return;
    dfs(brother[i],j);
    f[i][j]=f[brother[i]][j];
    for (int k=0;k<j;k++) {
        dfs(brother[i],k);
        dfs(child[i],j-k-1);
        f[i][j]=max(f[i][j],f[brother[i]][k]+f[child[i]][j-k-1]+score[i]);
    }
}
int main() {       
    cin>>n>>k;
    fill(score,score+302,-10000);
    score[n+1]=0;
    fill(brother,brother+n+1,0);
    fill(child,child+n+1,0);
    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=n+1;j++) {
            f[i][j]=0;
            vis[i][j]=false;
        }   
    int a,b;
    for(int i=1;i<=n;i++) {
        cin>>a>>b;
        if (a==0) a=n+1;
        brother[i]=child[a];
        child[a]=i;
        score[i]=b;
    }
    for (int i=1;i<=n+1;i++)
        f[i][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (child[i]==0) f[i][j]=score[i];
    dfs(n+1,k+1);
    cout<<f[n+1][k+1];
    return 0;
}