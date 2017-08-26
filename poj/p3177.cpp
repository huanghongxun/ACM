#include <cstdio>
const int N = 5010, M = 20010;

int h[N], p[M], v[M], cnt = 0;
int low[N], dfn[N], belong[N], degree[N], sta[M], instack[M];
int ts = 0, top = 0, bcc = 0;
void add(int x, int y) {
    p[++cnt] = h[u]; v[cnt] = y; h[u] = cnt++;
}
void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++ts;
    sta[++top] = u; instack[u] = 1;
    for (int i = h[u]; i; i = p[i]) {
        if (v[i] == fa) continue;
        if (!dfn[v[i]]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        bcc++;
        do {
            int v = sta[top--];
            instack[v] = 0;
            belong[v] = bcc;
        } while (v != u);
    }
}
int main() {
    int n, m, u, v, i, j;
    scanf("%d%d",&n,&m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d",&u,&v);
        add(u, v); add(v, u);
    }
    for (i = 1; i <= n; i++)
        if(!dfn[i]) tarjan(1, 0);
    for (i = 1; i <= n; i++)
        for (j = h[u]; j; j = p[j])
            if (belong[i] != belong[v[j])
                degree[belong[i]]++;
    int sum = 0;
    for (i = 1; i <= n; i++)
        if (degree[i] == 1)
            sum++;
    printf("%d\n", (sum + 1) / 2);
    return 0;
}