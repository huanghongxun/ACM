// UVALive 5774, UVALive 5738
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
const int N = 150005;

int k;
int h[N], p[N], v[N], edge = 0;
int cnt[N];
int val[N];
int dp[N][305];

void add(int a, int b) {
    p[++edge] = h[a]; v[edge] = b; h[a] = edge;
}

void dfs(int now) {
    int i, j, s;
    cnt[now] = 0;
    if (!h[now]) {
        cnt[now] = 1;
        dp[now][1] = val[now];
        return;
    }

    for (i = h[now]; i; i = p[i]) {
        dfs(v[i]);
        cnt[now] += cnt[v[i]];
    }

    cnt[now] = min(cnt[now], k);

    FOR(i,0,cnt[now]) dp[now][i] = -1;
    dp[now][0]=0;

    for (i = h[now]; i; i = p[i])
        for (j = cnt[now]; j >= 0; --j)
            for (s = 0; s <= j && s <= cnt[v[i]]; ++s)
                if (dp[v[i]][s] != -1 && dp[now][j - s] != -1)
                    dp[now][j] = max(dp[now][j], dp[v[i]][s] + dp[now][j-s]);
    dp[now][1] = max(val[now], dp[now][1]);
}

int main() {
    int i, n, fa, root;
    while (scanf("%d%d", &n, &k) != EOF) {
        FOR(i,1,n) h[i] = 0;
        edge = 0;
        FOR(i,1,n) {
            scanf("%d%d", &fa, &val[i]);
            if (!fa) root = i;
            else add(fa, i);
        }

        dfs(root);
        if (cnt[root] < k || dp[root][k] == -1) puts("impossible");
        else printf("%d\n", dp[root][k]);
    }
    return 0;
}