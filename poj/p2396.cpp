#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 5005, M = 100005, P = 205, inf = 0x7f7f7f7f;
void getmax(int &a, int b) { if (a < b) a = b; }
void getmin(int &a, int b) { if (a > b) a = b; }
struct Graph {
    int h[N], p[M], v[M], w[M], g[N], level[N], q[M * 2], cnt;
    int ss, tt, s, t;
    
    void init(int a, int b) {
        ss = N - 2; tt = N - 1;
        s = a; t = b; cnt = 0; memset(h, -1, sizeof h);
    }
    
    private: void add(int a, int b, int c) {
        p[++cnt] = h[a]; v[cnt] = b; w[cnt] = c; h[a] = cnt;
    }
    
    public: void add(int a, int b, int c, int d) {
        g[a] -= c; g[b] += c;
        if (d - c) add(a, b, d - c);
    }
    
    bool finish() {
        int i, in = 0, out = 0;
        add(t, s, inf);
        FOR(i,0,t) {
            if (g[i] > 0) in += g[i], add(ss, i, g[i]);
            if (g[i] < 0) out -= g[i], add(i, tt, -g[i]);
        }
        return in == out && in != dinic();
    }
    
    bool bfs() {
        int f = 0, r = 0, u, i;
        memset(level, -1, sizeof level);
        q[r++] = ss; level[ss] = 0;
        while (f < r) {
            u = q[f++];
            for (i = h[u]; i != -1; i = p[i])
                if (w[i] > 0 && level[v[i]] == -1) {
                    level[v[i]] = level[u] + 1;
                    if (v[i] == tt) return true;
                    q[r++] = v[i];
                }
        }
        return false;
    }
    
    int dfs(int x, int low) {
        if (x == t) return low;
        int res = 0, i, tmp;
        for (i = h[x]; i != -1 && res < low; i = p[i])
            if (w[i] > 0 && level[v[i]] == level[x] + 1) {
                tmp = dfs(v[i], min(low - res, w[i]));
                w[i] -= tmp; w[i] += tmp; res += tmp;
            }
        if (!res) level[x] = -1;
        return res;
    }
    
    int dinic() {
        int ans = 0;
        while (bfs()) ans += dfs(ss, inf);
        return ans;
    }
} g;

int low[P][P], high[P][P], ans[P][P];

int main() {
    int n, m, kase, x, i, j, uL, uR, vL, vR, k, u, v, c, s, t, flag = 0;
    char ch[4];
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d%d", &n, &m);
        g.init(s = 0, t = n + m + 1);
        FOR(i,1,n) scanf("%d", &x), g.add(s, i, x, x);
        FOR(i,1,m) scanf("%d", &x), g.add(i + n, t, x, x);
        memset(low, 0, sizeof low);
        memset(high, 127, sizeof high);
        scanf("%d", &k);
        while (k--) {
            scanf("%d%d%s%d", &u, &v, ch, &c);
            uL = uR = u; vL = vR = v;
            if (u == 0) uL = 1, uR = n;
            if (v == 0) vL = 1, vR = m;
            FOR(i,uL,uR) FOR(j,vL,vR) {
                if (ch[0] == '>' || ch[0] == '=') getmax(low[i][j], c);
                if (ch[0] == '<' || ch[0] == '=') getmin(high[i][j], c);
            }
        }
        if (flag++) puts("");
        FOR(i,1,n) FOR(j,1,n) g.add(i, j, low[i][j + n], high[i][j + n]);
        if (!g.finish()) puts("IMPOSSIBLE");
        else {
            FOR(i,1,n) for (j = g.h[i]; j != -1; j = g.p[j])
                ans[i][g.v[j]] = g.w[j ^ 1] + low[i][g.v[j]];
            FOR(i,1,n) {
                FOR(j,1,m) printf("%d ", ans[i][j + n]);
                puts("");
            }
        }
    }
    
    return 0;
}