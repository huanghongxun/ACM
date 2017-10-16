#include <cstdio>
#define FOR(i,j,k) for(int i=j;i<=k;++i)
const int N = 16;
int f[N], g[N];
int ans = 0, n;
void dfs(int a, int b) {
    if (a >= n) {
        FOR(i,1,n) if (g[i] != f[i]) return;
        ++ans;
    }
    else if ((n - a + 1) * 3 + g[a] < f[a]);
    else if ((n - b + 1) * 3 + g[b] < f[b]);
    else if (b == n) {
        if (g[a] + 3 == f[a]) {
            g[a] += 3;
            dfs(a + 1, a + 2);
            g[a] -= 3;
        } else
        if (g[a] + 1 == f[a] && g[b] + 1 <= f[b]) {
            ++g[a]; ++g[b];
            dfs(a + 1, a + 2);
            --g[a]; --g[b];
        } else
        if (g[a] == f[a] && g[b] + 3 <= f[b]) {
            g[b] += 3;
            dfs(a + 1, a + 2);
            g[b] -= 3;
        }
    } else {
        if (g[a] + 3 <= f[a]) {
            g[a] += 3;
            dfs(a, b + 1);
            g[a] -= 3;
        } else
        if (g[a] + 1 <= f[a] && g[b] + 1 <= f[b]) {
            ++g[a]; ++g[b];
            dfs(a, b + 1);
            --g[a]; --g[b];
        } else
        if (g[b] + 3 <= f[b]) {
            g[b] += 3;
            dfs(a, b + 1);
            g[b] -= 3;
        }
    }
}

int main() {
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", f + i);
    dfs(1, 2);
    printf("%d", ans);
    return 0;
}