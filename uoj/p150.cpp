#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i = j; i <= k; i++)
const int N = 300005, M = N * 2;

int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}

struct Path {
    int u, v, a, l;
} path[N];
int fa[N], dep[N], dis[N], flag[N], son[N], sz[N], top[N], q[N], topo = 0;
int h[N], p[M], v[M], w[M], edge = 0, n, m;
void add(int a, int b, int c) {
    p[++edge] = h[a]; v[edge] = b; w[edge] = c; h[a] = edge;
}

void dfs(int x) {
    sz[x] = 1; q[++topo] = x;
    for (int i = h[x]; i; i = p[i])
        if (v[i] != fa[x]) {
            fa[v[i]] = x; dep[v[i]] = dep[x] + 1;
            dis[v[i]] = dis[x] + w[i];
            dfs(v[i]);
            sz[x] += sz[v[i]];
            if (sz[v[i]] > sz[son[x]]) son[x] = v[i];
        }
}

void dfs(int x, int t) {
    top[x] = t;
    if (son[x]) dfs(son[x], t);
    for (int i = h[x]; i; i = p[i])
        if (v[i] != fa[x] && v[i] != son[x])
            dfs(v[i], v[i]);
}

int lca(int a, int b) {
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        a = fa[top[a]];
    }
    return dep[a] < dep[b] ? a : b;
}

bool judge(int mid) {
    int l = 0, i, x = 0;
    FOR(i,1,n) flag[i] = 0;
    FOR(i,1,m) if (path[i].l > mid) {
        flag[path[i].u]++;
        flag[path[i].v]++;
        flag[path[i].a] -= 2;
        l = max(l, path[i].l - mid);
        ++x;
    }
    if (!x) return true;
    for (i = topo; i; --i) flag[fa[q[i]]] += flag[q[i]];
    for (i = 1; i <= edge; i += 2) {
        int a = v[i], b = v[i + 1];
        if (dep[a] < dep[b]) swap(a, b);
        if (w[i] >= l && flag[a] == x)
            return true;
    }
    return false;
}

int main() {
    int a, b, c, i, l = 0, r = 0, mid, ans = 0;
    n = read(), m = read();
    FOR(i,2,n) {
        a = read(); b = read(); c = read();
        add(a, b, c); add(b, a, c);
        r += c;
    }
    dfs(1); dfs(1, 1);
    FOR(i,1,m) {
        a = read(); b = read(); c = lca(a, b);
        path[i] = (Path) { a, b, c, dis[a] + dis[b] - 2 * dis[c] };
    }
    while (l <= r) {
        mid = l + r >> 1;
        if (judge(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    printf("%d", ans);
    return 0;
}