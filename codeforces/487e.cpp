#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>
#include <cstring>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;i++)
int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; '0' > ch || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}

const int N = 100001, M = 2 * N;

struct Graph {
    int head[N], next[M], to[M], cnt;
    Graph() : cnt(0) {}
    void add(int u, int v) {
        next[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
        next[++cnt] = head[v]; head[v] = cnt; to[cnt] = u;
    }
};

struct BCC : Graph {
    int dfn[N], low[N], id[N], belong[N], cut[N], cnt;
    multiset<int> val[M];

    BCC() {
        cnt = 0;
    }

    function<void(int,int)> found_cut_point;
    
    void tarjan(int u) {
        static int ts = 0, top = 0;
        static int stack[N];
        int x, i;
        dfn[u] = low[u] = ++ts;
        stack[++top] = u;
        for (i = head[u]; i; i = next[i])
            if (!dfn[to[i]]) {
                tarjan(to[i]);
                low[u] = min(low[u], low[to[i]]);
                if (dfn[u] == low[to[i]]) {
                    cnt ++;
                    cut[u] = 1;
                    do {
                        x = stack[top--];
                        id[x] = cnt;
                        if (cut[x])
                            found_cut_point(x, cnt);
                    } while(x != to[i]);
                    found_cut_point(u, cnt);
                }
            } else low[u] = min(low[u], dfn[to[i]]);
    }
} bcc;

struct SegmentTree {
    int initial[M], mi[M];
    
    int build(int t, int l, int r) {
        if (l == r) return mi[t] = initial[l];
        int mid = l + r >> 1;
        return mi[t] = min(build(t * 2, l, mid), build(t * 2 + 1, mid + 1, r));
    }
    
    int query(int t, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) return mi[t];
        int mid = l + r >> 1;
        if (qr <= mid) return query(t * 2, l, mid, ql, qr);
        else if (ql > mid) return query(t * 2 + 1, mid + 1, r, ql, qr);
        else return min(query(t * 2, l, mid, ql, mid),
            query(t * 2 + 1, mid + 1, r, mid + 1, qr));
    }
    
    void modify(int t, int l, int r, int x, int v) {
        if (l == r) { mi[t] = v; return; } 
        int mid = l + r >> 1;
        if (x <= mid) modify(t * 2, l, mid, x, v);
        else modify(t * 2 + 1, mid + 1, r, x, v);
        mi[t] = min(mi[t * 2], mi[t * 2 + 1]);
    }
} seg;

struct Tree : Graph {
    int son[N], sz[N], top[N], dep[N], pos[N], fa[N], id;
    SegmentTree *st;

    Tree() {
        id = 0;
    }
    
    void dfs1(int x) {
        son[x] = 0; sz[x] = 1;
        for (int i = head[x]; i; i = next[i])
            if (to[i] != fa[x]) {
                fa[to[i]] = x; dep[to[i]] = dep[x] + 1;
                dfs1(to[i]);
                sz[x] += sz[to[i]];
                if (sz[to[i]] > sz[son[x]]) son[x] = to[i];
            }
    }
    
    void dfs2(int x, int t) {
        top[x] = t; pos[x] = ++id;
        if (son[x]) dfs2(son[x], t);
        for (int i = head[x]; i; i = next[i])
            if (to[i] != fa[x] && to[i] != son[x])
                dfs2(to[i], to[i]);
    }
    
    int lca(int x, int y) {
        int fx = top[x], fy = top[y];
        while (fx != fy) {
            if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y);
            x = fa[fx], fx = top[x];
        }
        if (dep[x] > dep[y]) swap(x, y);
        return x;
    }
    
    int query(int x, int y) {
        int fx = top[x], fy = top[y], ans = 2147483647;
        while (fx != fy) {
            if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y);
            ans = min(ans, st->query(1, 1, id, pos[fx], pos[x]));
            x = fa[fx], fx = top[x];
        }
        if (dep[x] > dep[y]) swap(x, y);
        return min(ans, st->query(1, 1, id, pos[x], pos[y]));
    }
} tree;

int main() {
    static int w[N];
    char ch[2];
    int n = read(), m = read(), q = read(), i, x, y;
    FOR (i, 1, n) w[i] = read();
    tree.st = &seg;
    bcc.found_cut_point = [n] (int id, int bcc) {
        tree.add(id + n, bcc);
    };
    while (m--) bcc.add(read(), read());
    bcc.tarjan(1);
    FOR (i, 1, n) {
        if (i != 1)
            bcc.val[bcc.id[i]].insert(w[i]);
        if (bcc.cut[i])
            bcc.val[n + i].insert(2147483647);
    }
    tree.dfs1(n+1); tree.dfs2(n+1, n+1);
    memset(seg.initial, 127, sizeof seg.initial);
    FOR (i, 1, 2*n) if(tree.pos[i]) seg.initial[tree.pos[i]] = *bcc.val[i].begin();
    seg.build(1, 1, tree.id);
    while (q--) {
        scanf("%s%d%d", ch, &x, &y);
        if (ch[0] == 'C') {
            if (x != 1) {
                bcc.val[bcc.id[x]].erase(bcc.val[bcc.id[x]].find(w[x]));
                bcc.val[bcc.id[x]].insert(y);
                seg.modify(1, 1, tree.id, tree.pos[bcc.id[x]], *bcc.val[bcc.id[x]].begin());
            }
            w[x] = y;
        } else {
            if (x == y) printf("%d\n", w[x]);
            else {
                x=bcc.cut[x]?x+n:bcc.id[x];  
                y=bcc.cut[y]?y+n:bcc.id[y];
                int l = tree.lca(x, y);
                if (l <= bcc.cnt) l = tree.fa[l];
                printf("%d\n", min(w[l - n], tree.query(x, y));
            }
        }
    }
    return 0;
}
