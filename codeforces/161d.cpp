#include <cstdio>
typedef long long ll;
const int N = 50001, M = N * 2;
int head[N] = {0}, next[M], to[M], cnt = 0, n, k;
void add(int u, int v) { next[++cnt] = head[u]; head[u] = cnt; to[cnt] = v; }
ll ans, f[N][502] = {0};
void dfs(int u, int fa) {
    f[u][0] = 1;
    int i, j;
    for(i = head[u]; i; i = next[i])
        if(to[i] != fa) {
            dfs(to[i], u);
            for (j = 0; j <= k; j++)
                f[u][j + 1] += f[to[i]][j];
        }
    ans += f[u][k];
    ll tmp = 0;
    for(i = head[u]; i; i = next[i]) if(to[i] != fa)
        for (j = 1; j < k; j++)
            tmp += f[to[i]][j - 1] * (f[u][k - j] - f[to[i]][k - j - 1]);
    ans += tmp / 2;
}
int main() {
    int x, y, i;
    scanf("%d%d", &n, &k);
    for (i = 1; i < n; i ++) {
        scanf("%d%d", &x, &y);
        add(x, y); add(y, x);
    }
    dfs(1, 1);
    printf("%I64d", ans);
    return 0;
}