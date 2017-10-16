#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 128;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
bool vis[N][N];
char map[N][N];
int n;

void dfs(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n) return;
    if (vis[x][y]) return;
    if (map[x][y] == '#') return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i)
        dfs(x + dx[i], y + dy[i]);
}

int main() {
    int i, j, ans = 0;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%s", map[i] + 1);
    dfs(1, 1); dfs(n, n);
    FOR(i,1,n) FOR(j,1,n) if (vis[i][j])
        for (int k = 0; k < 4; ++k)
            if (!vis[i + dx[k]][j + dy[k]])
                ++ans;
    printf("%d\n", (ans - 4) * 9);
    return 0;
}