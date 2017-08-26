#include <cstdio>
const int N = 100005, M = N * 2;
int dp[N], h[N], p[M], v[M], in[N], out[N], entry[N], cnt = 0;
void add(int a, int b) {
    p[++cnt] = h[a]; v[cnt] = b; h[a] = cnt; ++in[b];
}
void dfs(int x) {
    for (int i = h[x]; i; i = p[i]) {
        dp[v[i]] += dp[x]; --in[v[i]];
        if (!in[v[i]]) dfs(v[i]);
    }
}
int main() {
    int n, m, i, a, b, ans = 0;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for (i = 1; i <= n; ++i)
        entry[i] = !in[i] && h[i];
    for (i = 1; i <= n; ++i)
        if (entry[i])
            dp[i] = 1, dfs(i);
    for (i = 1; i <= n; ++i)
        if (!h[i]) ans += dp[i];
    printf("%d", ans);
    return 0;
}