#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 200000, M = 4000000;
using namespace std;

int d[N], h[N], p[M], v[M], w[M], vis[N], cnt = 0;
void add(int x, int y, int z) {
    v[++cnt] = y; w[cnt] = z; p[cnt] = h[x]; h[x]=cnt;
}
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int ans1;
void dfs(int x) {
    vis[x] = 1;
    for (int i = h[x]; i; i = p[i]) {
        if (vis[v[i]])
            ans1 = gcd(ans1, abs(d[x] + w[i] - d[v[i]]));
        else {
            d[v[i]] = d[x] + w[i];
            dfs(v[i]);
        }
    }
}
int ma, mi;
void tree(int x) {
    vis[x] = 1;
    ma = max(ma, d[x]), mi = min(mi, d[x]);
    for (int i = h[x]; i; i = p[i])
        if (!vis[v[i]]) {
            d[v[i]] = d[x] + w[i];
            tree(v[i]);
        }
}

int main() {
    int i, a, b, n, m, ans2;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b, 1); add(b, a, -1);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i]) dfs(i);
    if (ans1)
        for (ans2 = 3; ans2 < ans1 && ans1 % ans2; ans2++);
    else {
        memset(vis, 0, sizeof vis);
        for (i = 1; i <= n; i++)
            if (!vis[i]) {
                ma = mi = d[i] = 0;
                tree(i);
                ans += ma - mi + 1;
            }
        ans2 = 3;
    }
    if (ans1 < 3) ans1 = ans2 = -1;
    printf("%d %d", ans1, ans2);
    return 0;
}