#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 200005, M = N * 2;
int vis[N], c[N], h[N], v[M], p[M], cnt = 0;
int cc[N], ma;
void add(int a, int b) {
    p[++cnt] = h[a]; v[cnt] = b; h[a] = cnt;
}

int dfs(int x) {
    int ans = 1;
    vis[x] = 1;
    ma = max(ma, ++cc[c[x]]);
    for (int i = h[x]; i; i = p[i])
        if (!vis[v[i]]) ans += dfs(v[i]);
    return ans;
}

int main() {
    int a, b, n, m, k, i, j, temp, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    FOR(i,1,n) scanf("%d", &c[i]);
    FOR(i,1,m) {
        scanf("%d%d", &a, &b);
        add(a, b); add(b, a);
    }
    FOR(i,1,n) if (!vis[i]) {
        FOR(j,1,k) cc[i] = 0;
        ma = 0;
        temp = dfs(i);
        ans += temp - ma;
    }
    printf("%d", ans);
    return 0;
}