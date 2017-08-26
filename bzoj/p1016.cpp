#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;
typedef long long ll;
const int mod = 31011, N = 2005;
ll read() {
    ll s = 0, f = 1; char ch = getchar();
    for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
    for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
    return s * f;
}
struct Edge { int a, b, i; ll c; } e[N];
bool operator< (Edge a, Edge b) { return a.c < b.c;}
int fa[N], vis[N], color[N], cnt[N], ts, n, m, cc = 0;
ll ans = 0;
vector<int> belong[N];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool kruskal() {
    int i, j, a, b, tot = 0;
    FOR(i,1,n) fa[i] = i;
    sort(e + 1, e + m + 1);
    FOR(i,1,m) {
        a = find(e[i].a), b = find(e[i].b);
        if (a != b) {
            fa[a] = b; ans += e[i].c;
            FOR(j,1,cc) if (color[j] == e[i].c)
            { ++cnt[j]; break; }
            if (++tot >= n - 1) return 1;
        }
    }
    return 0;
}
bool ok() {
    int i, j, a, b; ll z = 0;
    FOR(i,1,n) fa[i] = i;
    FOR(i,1,m) if (vis[e[i].i] != ts) {
        a = find(e[i].a), b = find(e[i].b);
        if (a != b) fa[a] = b, z += e[i].c;
    }
    return z == ans;
}
int calc(int j) {
    int z = 0;
    for (; j; j -= j & -j) ++z;
    return z;
}
int main() {
    int i, j, k, z = 1;
    n = read(); m = read();
    FOR(i,1,m) e[i].a = read(), e[i].b = read(), e[i].c = read(), e[i].i = i;
    FOR(i,1,m) if (!vis[i]) {
        color[++cc] = e[i].c;
        belong[cc].push_back(i);
        FOR(j,i+1,m) if (e[i].c == e[j].c)
            vis[j] = 1, belong[cc].push_back(j);
    }
    if (!kruskal()) return puts("0"), 0;
    memset(vis, 0, sizeof vis); ts = 0;
    FOR(j,1,cc) {
        if (!cnt[j]) continue;
        int tmp = 0;
        rep(i,0,(1<<belong[j].size()))
            if (calc(i) == cnt[j]) {
                ++ts;
                rep(k,0,belong[j].size())
                    if (!((i >> k) & 1))
                        vis[belong[j][k]] = ts;
                tmp += ok();
            }
        if (tmp) z = (1ll * z * tmp) % mod;
    }
    printf("%d", z);
    return 0;
}
