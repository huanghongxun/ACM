#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
const int N = 210;
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, idx, tot;
int maz[N][N], done[N * N], ans[N * N];
char mp[N][N];

struct Point {
    int x, y;
    Point navigate(int dir) { return (Point) { x + dx[dir], y + dy[dir] }; }
    bool remain() { return 1 <= x && x <= n && 1 <= y && y <= m; }
    bool operator ==(const Point &b) const { return x == b.x && y == b.y; }
} q[N * N];
 
void bfs(int x, int y) {
    int l = 0, r = 0, i;
    mp[x][y] = 0;
    q[r++] = (Point) {x, y};
    while (l < r) {
        Point u = q[l++];
        maz[u.x][u.y] = idx;
        FOR(i,0,7) {
            Point v = u.navigate(i);
            if (v.remain() && mp[v.x][v.y]) {
                mp[v.x][v.y] = 0;
                q[r++] = v;
            }
        }
    }
    if (r <= 4)
        done[idx] = 1;
}
 
void solve(int x, int y) {
    Point u = (Point) {x, y};
    int i = 0, to = 6;
    q[i++] = u;
    while (true) {
        int flag = 0;
        for (int j = to; j != to || !flag; j = (j + 1) % 8) {
            if (j == to)
                flag = 1;
            Point v = u.navigate(j);
            if (v.remain() && maz[v.x][v.y] == maz[x][y]) {
                u = u.navigate((j + 7) % 8);
                FOR(j,0,7) if (v.navigate(j) == u) {
                    to = j;
                    break;
                }
                q[i++] = v;
                u = v;
                if (i >= 4 && q[0] == q[i - 2] && q[1] == q[i - 1]) {
                    ans[++tot] = i - 2;
                    return;
                }
                break;
            }
        }
    }
}
 
int main() {
    int kase = 0, i, j;
    while (scanf("%d%d", &n, &m) == 2 && m && n) {
        FOR(i,1,n) {
            scanf("%s", mp[i] + 1);
            FOR(j,1,m) mp[i][j] -= '0';
        }
        idx = 0;
        memset(maz, 0, sizeof(maz));
        FOR(i,1,n) FOR(j,1,m) if (mp[i][j]) {
            done[++idx] = 0;
            bfs(i, j);
        }
        tot = 0;
        FOR(i,1,n) FOR(j,1,m) if (maz[i][j] && !done[maz[i][j]]) {
            done[maz[i][j]] = 1;
            solve(i, j);
        }
        printf("Case %d\n", ++kase);
        if (tot) {
            sort(ans + 1, ans + tot + 1);
            FOR(i,1,tot) printf("%d%c", ans[i], (i == tot) ? '\n' : ' ');
        } else
            puts("no objects found");
    }
    return 0;
}