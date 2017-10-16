#include <cstdio>
#include <algorithm>
using namespace std;

const int inf = 0x7fffffff, N = 100005, E = 2 * N, M = 4 * N;

int sw[M], sa[M], w[M], be[N], init[N];
int fa[N], son[N], sonc[N], top[N], sz[N], dep[N], pos[N], id = 0;
int h[N], v[E], p[E], c[E], edge = 0;
int n;

void add(int a, int b, int k) {
    p[++edge] = h[a]; v[edge] = b; c[edge] = k; h[a] = edge;
}

void dfs(int x) {
    sz[x] = 1;
    for (int i = h[x]; i; i = p[i])
        if (v[i] != fa[x]) {
            fa[v[i]] = x; dep[v[i]] = dep[x] + 1;
            be[(i + 1) / 2] = v[i];
            dfs(v[i]);
            sz[x] += sz[v[i]];
            if (sz[v[i]] > sz[son[x]]) son[x] = v[i], sonc[x] = c[i];
        }
}

void dfs(int x, int t, int r) {
    top[x] = t; pos[x] = ++id; init[id] = r;
    if (son[x]) dfs(son[x], t, sonc[x]);
    for (int i = h[x]; i; i = p[i])
        if (v[i] != fa[x] && v[i] != son[x])
            dfs(v[i], v[i], c[i]);
}

void build(int t, int l, int r) {
    sw[t] = inf;
    if (l == r) w[t] = init[l];
    else {
        int mid = l + r >> 1;
        build(t * 2, l, mid);
        build(t * 2 + 1, mid + 1, r);
        w[t] = max(w[t * 2], w[t * 2 + 1]);
    }
}

void cover_flag(int t, int qw) {
    if (qw != inf) w[t] = sw[t] = qw, sa[t] = 0;
}

void add_flag(int t, int qa) {
    w[t] += qa; sa[t] += qa;
}

void pushdown(int t) {
    if (sw[t] != inf) {
        cover_flag(t * 2, sw[t]);
        cover_flag(t * 2 + 1, sw[t]);
        sw[t] = inf;
    }
    if (sa[t]) {
        add_flag(t * 2, sa[t]);
        add_flag(t * 2 + 1, sa[t]);
        sa[t] = 0;
    }
}

void modify(int t, int l, int r, int ql, int qr, int qw, int qa) {
    pushdown(t);
    if (l == ql && r == qr) {
        cover_flag(t, qw);
        add_flag(t, qa);
        return;
    }
    int mid = l + r >> 1;
    if (qr <= mid) modify(t * 2, l, mid, ql, qr, qw, qa);
    else if (mid < ql) modify(t * 2 + 1, mid + 1, r, ql, qr, qw, qa);
    else modify(t * 2, l, mid, ql, mid, qw, qa), modify(t * 2 + 1, mid + 1, r, mid + 1, qr, qw, qa);
    w[t] = max(w[t * 2], w[t * 2 + 1]);
}

int query(int t, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) return w[t];
    pushdown(t);
    int mid = l + r >> 1;
    if (qr <= mid) return query(t * 2, l, mid, ql, qr);
    else if (mid < ql) return query(t * 2 + 1, mid + 1, r, ql, qr);
    else return max(query(t * 2, l, mid, ql, mid), query(t * 2 + 1, mid + 1, r, mid + 1, qr));
}

int tree_query(int x, int y) {
    int tx = top[x], ty = top[y], ans = -inf;
    while (tx != ty) {
        if (dep[tx] < dep[ty]) swap(tx, ty), swap(x, y);
        ans = max(ans, query(1, 1, n, pos[tx], pos[x]));
        x = fa[tx], tx = top[x];
    }
    if (x == y) return ans;
    if (dep[x] > dep[y]) swap(x, y);
    return max(ans, query(1, 1, n, pos[x] + 1, pos[y]));
}

void tree_modify(int x, int y, int qw, int qa) {
    int tx = top[x], ty = top[y];
    while (tx != ty) {
        if (dep[tx] < dep[ty]) swap(tx, ty), swap(x, y);
        modify(1, 1, n, pos[tx], pos[x], qw, qa);
        x = fa[tx], tx = top[x];
    }
    if (x == y) return;
    if (dep[x] > dep[y]) swap(x, y);
    modify(1, 1, n, pos[x] + 1, pos[y], qw, qa);
}

int main() {
    int i, a, b, c; char op[8];
    scanf("%d", &n);
    for (i = 1; i < n; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c); add(b, a, c);
    }
    dfs(1); dfs(1, 1, 99999999); build(1, 1, n);
    while (scanf("%s", op) != EOF && op[1] != 't') {
        scanf("%d%d", &a, &b);
        if (op[1] == 'a') {
            printf("%d\n", tree_query(a, b));
        } else if (op[1] == 'o') {
            scanf("%d", &c);
            tree_modify(a, b, c, 0);
        } else if (op[1] == 'd') {
            scanf("%d", &c);
            tree_modify(a, b, inf, c);
        } else if (op[1] == 'h') {
            modify(1, 1, n, pos[be[a]], pos[be[a]], b, 0);
        }
    }
    return 0;
}