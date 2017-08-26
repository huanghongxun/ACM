#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 5001;
vector<int> adj[N];
int sz[N], f[N][N];
int n;

void dfs(int u, int fa) {
    if (adj[u].size() == 1) sz[u] = 1;
    int i, v, p, j;
    for (i = 1; i <= n; i++) f[u][i] = 0x3f3f3f3f;
    for (p = 0; p < adj[u].size(); p++) {
        v = adj[u][p];
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    for (p = 0; p < adj[u].size(); p++) {
        v = adj[u][p];
        if (v == fa) continue;
        for(int i = sz[u]; i >= 0; i--)
            for(int j = 0; j <= sz[v]; j++)
                if(i + j <= sz[u])
                    f[u][i + j] = min(f[u][i + j], f[u][i] + f[v][j]);
    }
    for (i = 0; i <= sz[u]; i++)
        f[u][i] = min(f[u][i], f[u][sz[u] - i] + 1);
}

int main() {
    scanf("%d", &n);
    if (n == 2) { puts("1"); return 0;}
    int u, v, i, root = 1;
    for (i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while(adj[root].size() == 1) root++;
    dfs(root, 0);
    printf("%d", f[root][sz[root] / 2]);
    return 0;
}
