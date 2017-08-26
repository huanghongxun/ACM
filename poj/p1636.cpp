#include <cstdio>
#include <cstring>
using namespace std;
bool map[203][203], mark[2][202], dp[203][203];
int n, m;
int l, r;
void dfs(int s, int x) {
    int i;
    mark[s][x]=true;
    if(s) {
        for(i=1,r++;i<=n;i++)
            if(map[i][x]&&!mark[0][i])
                dfs(0,i);
    } else {
        for(i=1,l++;i<=n;i++)
            if(map[x][i]&&!mark[1][i])
                dfs(1,i);
    }
}
int main() {
    int i,j,k,T,x,y;
    scanf("%d",&T);
    while(T--&&scanf("%d %d",&n,&m)) {
        memset(mark,0,sizeof(mark));
        memset(map,0,sizeof(map));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++) {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        dp[0][0]=true;
        for(i=1;i<=n;i++) {
            if(mark[0][i])continue;
            l=r=0;dfs(0,i);
            for(j=n/2;j>=l;j--)
                for(k=n/2;k>=r;k--)
                    if(dp[j-l][k-r])dp[j][k]=true;
        }
        for(i=1;i<=n;i++) {
            if(mark[1][i])continue;
            l=r=0;dfs(1,i);
            for(j=n/2;j>=l;j--)
                for(k=n/2;k>=r;k--)
                    if(dp[j-l][k-r])dp[j][k]=true;
        }
        for(i=n/2;i>=0;i--)
            if(dp[i][i])break;
        printf("%d\n",i);
    }
    return 0;
}