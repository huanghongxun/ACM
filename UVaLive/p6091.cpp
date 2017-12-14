// UVALive 6091
#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 505, M = N * N;

int h[N], p[M], v[M], d[N], vis[N], cnt = 0;

int add(int a, int b) {
    p[++cnt] = h[a]; v[cnt] = b; h[a] = cnt; ++d[a];
}

void dfs(int x, int &vertices, int &edges) {
    vis[x] = 1;
    ++vertices;
    for (int i = h[x]; i; i = p[i]) {
        ++edges;
        if (!vis[v[i]])
            dfs(v[i], vertices, edges);
    }
}

int main() {
    int i, trees = 0, kase = 0, x, y, n, m;
    while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
        cnt = trees = 0;
        memset(h, 0, sizeof h);
        memset(vis, 0, sizeof vis);
        FOR(i,1,m) {
            scanf("%d%d", &x, &y);
            add(x, y); add(y, x);
        }
        FOR(i,1,n) if (!vis[i]) {
            int vertices = 0, edges = 0;
            dfs(i, vertices, edges);

            if (2 * (vertices - 1) == edges)
                ++trees;
        }
        printf("Case %d: ", ++kase);
        if (trees == 0) puts("No trees.");
        else if (trees == 1) puts("There is one tree.");
        else printf("A forest of %d trees.\n", trees);
    }

    return 0;
}