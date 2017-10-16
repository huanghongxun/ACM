#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)

int read() {
    int s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}
const int N = 300005, M = N * 2, K = 18;
int h[N], p[M], v[M], w[M], q[M], cnt = 0;
int fa[N][K + 1], dep[N], dis[N];
int mx[M], my[M], mlen[M], mlca[M], m, n;
int topo[N], tnum = 0, stk[N], flag[N];

void add(int a, int b, int c) {
    p[++cnt] = h[a]; v[cnt] = b; w[cnt] = c; h[a] = cnt;
}

int dfs(int x) {
    int i, top = 0;
    stk[++top] = x;
    while (top) {
        topo[++tnum] = x = stk[top--];
        FOR(i,1,K) fa[x][i] = fa[fa[x][i - 1]][i - 1];
        for (i = h[x]; i; i = p[i])
            if (v[i] != fa[x][0]) {
                fa[v[i]][0] = x;
                q[v[i]] = w[i];
                dep[v[i]] = dep[x] + 1;
                dis[v[i]] = dis[x] + w[i];
                stk[++top] = v[i];
            }
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int t = dep[x] - dep[y], i;
    FOR(i,0,K) if (t & (1 << i)) x = fa[x][i];
    for (i = K; ~i; --i) if (fa[x][i] != fa[y][i])
        x = fa[x][i], y = fa[y][i];
    return x == y ? x : fa[x][0];
}

bool judge(int mid) {
    int i, delta = 0, num = 0;
    FOR(i,1,n) flag[i] = 0;
    FOR(i,1,m) if (mlen[i] > mid) {
        flag[mx[i]]++;
        flag[my[i]]++;
        flag[mlca[i]] -= 2;
        delta = max(delta, mlen[i] - mid);
        ++num;
    }
    if (!num) return true;
    for (i = tnum; i; --i) flag[fa[topo[i]][0]] += flag[topo[i]];
    FOR(i,1,n) if (flag[i] == num && q[i] >= delta)
        return true;
    return false;
}

int main() {
    int i, a, b, c, ans = 0;
    n = read(); m = read();
    FOR(i,2,n) {
        a = read(); b = read(); c = read();
        add(a, b, c); add(b, a, c);
    }
    dfs(1); a = b = 0;
    FOR(i,1,m) {
        mx[i] = read(); my[i] = read(); mlca[i] = lca(mx[i], my[i]);
        mlen[i] = dis[mx[i]] + dis[my[i]] - 2 * dis[mlca[i]];
        b = max(b, mlen[i]);
    }
    while (a <= b) {
        c = a + b >> 1;
        if (judge(c)) b = c - 1, ans = c;
        else a = c + 1;
    }
    printf("%d", ans);
    return 0;
}