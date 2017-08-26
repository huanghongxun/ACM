#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 400005, M = N * 2;
int n, m;
int t, dfn[N], low[N];
int belong[N];
int bcc;
int h[N], p[M], v[M], cnt = 0;
int add(int a, int b) {
    p[++cnt] = h[a]; v[cnt] = b; h[a] = cnt;
    p[++cnt] = h[b]; v[cnt] = a; h[b] = cnt;
}
int stk[N], top = 0;

typedef pair<int, int> P;

set<P> reserve, should;

int tot[N];

struct Edge {int to, u, v;};

vector<Edge> ng[N];

void tarjan(int x, int fa = 0) {
    dfn[x] = low[x] = ++t;
    stk[++top] = x;
    for (int i = h[x]; i; i = p[i]) {
        if (v[i] == fa) continue;
        if (!dfn[v[i]]) {
            reserve.insert(P(x, v[i]));
            tarjan(v[i], x);

            if (low[x] > low[v[i]])
                low[x] = low[v[i]];
        } else if (low[x] > dfn[v[i]]) { 
            reserve.insert(P(x, v[i]));
            low[x] = dfn[v[i]];
        }
    }
    if (dfn[x] == low[x]) {
        int u; bcc++;
        do {
            belong[stk[top--]] = bcc;
            tot[bcc]++;
        } while (u != x);
    }
}

int r[N];
int dir[N];
bool diu;

void dfs(int v, int fa, int cost, int actualu = 0, int actualv = 0) {
    for (auto e : ng[v]) {
        if (e.to == fa) continue;

        dfs(e.to, v, cost, e.u, e.v);
    }

    if (r[v] >= cost && fa) {
        dir[v] = 1;
        r[fa] += r[v];
        if (diu) should.insert(P(actualu, actualv));
    } else if (r[v] < cost && fa) {
        if (diu) should.insert(P(actualv, actualu));
    }
}
void rdfs(int v, int fa) {
    if (dir[v] == 0) {
        r[v] += r[fa];
    }

    for (auto e : ng[v]) {
        if (e.to == fa) continue;
        rdfs(e.to, v);
    }
}
bool C(int x) {
    should.clear();

    memset(dir, 0, sizeof(dir));

    for (int i = 1; i <= bcc; i++) r[i] = tot[i];

    dfs(1, 0, x);
    rdfs(1, 0);


    for (int i = 1; i <= bcc; i++) if (r[i] < x) return false;

    return true;
}
int main() {
    scanf("%d %d", &n, &m);

    int x, y;
    vector<P> es;

    while (m--) {
        scanf("%d%d", &x, &y);
        add(x, y);
        es.push_back(P(x, y));
    }

    tarjan(1);

    vector<P> vec;

    for (auto p : reserve) if (belong[p.first] != belong[p.second]) vec.push_back(p);
    for (auto p : vec) reserve.erase(p);

    for (int x = 1; x <= n; x++) {
        for (int i = h[x]; i; i = p[i]) {
            int y = v[i];
            if (belong[x] != belong[y]) {
                ng[belong[x]].push_back((Edge){belong[x], x, y});
            }
        }
    }

    int l = 0, r = n + 1;

    while (r - l > 1) {
        int mid = (r + l) >> 1;

        if (C(mid)) l = mid;
        else r = mid;
    }

    diu = true;
    C(l);

    printf("%d\n", l);

    for (auto p : es) {
        if (reserve.find(p) != reserve.end() || should.find(p) != should.end()) {
            printf("%d %d\n", p.first, p.second);
            continue;
        }

        swap(p.first, p.second);

        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}