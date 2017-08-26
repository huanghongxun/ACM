#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define M 710
using namespace std;
const int dx[] = {0,0,1,-1}, int dy[] = {1,-1,0,0};
int n, m, a[M][M],f[M][M];
bool b[M][M];
int dfs(int x,int y) {
    if (b[x][y]) return 0;
    if (f[x][y]) return f[x][y];
    f[x][y] = 1;
    FOR(i,0,3) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > n)
            continue;
        if (a[nx][ny] >= a[x][y])
            continue;
        f[x][y] = max(f[x][y], dfs(nx,ny) + 1);
    }
    return f[x][y];
}
int main() {
    int x1, y1, x2, y2, z, t; char p[10];
    scanf("%d", &n);
    FOR(i,1,n) FOR(j,1,n) scanf("%d", &a[i][j]);
    scanf("%d", &m);
    while (m--) {
        scanf("%s", p); t = 0;
        switch(p[0]) {
            case 'C':
                scanf("%d%d%d", &x1, &y1, &z);
                a[x1][y1] = z;
                break;
            case 'S':
                t = 1;
            case 'B':
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                FOR(i,x1,x2) FOR(j,y1,y2) b[i][j] = t;
                break;
            case 'Q':
                t = 0;
                memset(f, 0, sizeof f);
                FOR(i,1,n) FOR(j,1,n)
                    t = max(t, dfs(i,j));
                printf("%d\n", t);
                break;
        }
    }
}