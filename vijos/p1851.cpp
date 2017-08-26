#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 1001
using namespace std;
int b[MAXN],c[MAXN][MAXN],s[MAXN],d[MAXN];
bool a[MAXN][MAXN];
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    memset(a,false,sizeof(a));
    memset(b,-1,sizeof(b));
    int n,m,l,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&s[i]);
        for(int j=1;j<=s[i];j++) scanf("%d",&c[i][j]);
    }
    for(int i=1;i<=m;i++){
        for(int j=c[i][1];j<=c[i][s[i]];j++) b[j]=0;
    }
    for(int i=1;i<=m;i++){
        l=1;
        for(int j=c[i][1];j<=c[i][s[i]];j++){
            if(j==c[i][l]) l++;
            else{
                for(int k=1;k<=s[i];k++){
                    if(a[j][c[i][k]]==0){
                        a[j][c[i][k]]=true;
                        b[c[i][k]]++;
                    }
                }
            }
        }
    }
    int temp=n;
    for(int i=1;i<=n;i++){
        if(b[i]==-1) temp--;
    }
    while(temp!=0)
    {
        ans++;
        int dl=0;
        for(int i=1;i<=n;i++){
            if(b[i]==0){
                dl++;
                d[dl]=i;
            }
        }
        temp-=dl;
        for(int i=1;i<=dl;i++){
            b[d[i]]=-1;
            for(int j=1;j<=n;j++){
                if(a[d[i]][j]==1) b[j]--;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}