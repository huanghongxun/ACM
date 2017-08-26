#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;
const int N = 101, M = 2 * N;
int far[N], len, to[M], next[M], head[N], cnt = 0;
void add(int u, int v) {
    next[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
}
void dfs(int u, int fa) {
    for (int i = head[u]; i; i = next[i])
        if (to[i] != fa) {
            dfs(to[i], u);
            len = max(len, far[u] + far[to[i]] + 1);
            far[u] = max(far[u], far[to[i]] + 1);
        }
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t, n, i, u, v, ans = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cnt = 0;
        memset(head, 0, sizeof head);
        memset(far, 0, sizeof far);
        for (i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        len = 0; dfs(1, 0); ans += len;
    }
    printf("%d", ans);
    return 0;
}