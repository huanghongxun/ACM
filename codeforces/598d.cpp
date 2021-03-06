#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;i++)
const int N = 1001;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};
char mp[N][N];
int scc[N][N], sz[N*N];
int ans, id = 0, n, m;
void dfs(int x, int y) {
    int i, nx, ny;
    scc[x][y] = id;
    FOR(i,0,3) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 < nx && nx <= n && 0 < ny && ny <= m && !scc[nx][ny]) {
            if (mp[nx][ny] == '*') ans++;
            else dfs(nx, ny);
        }
    }
}
int main() {
    int i, j, x, y, k;
    scanf("%d%d%d", &n, &m, &k);
    FOR(i,1,n) scanf("%s", mp[i]+1);
    memset(scc, 0, sizeof scc);
    FOR(i,1,n) FOR(j,1,m) if(mp[i][j]=='.'&&!scc[i][j])
        ans=0,++id,dfs(i,j),sz[id]=ans;
    while (k--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", sz[scc[x][y]]);
    }
    return 0;
}