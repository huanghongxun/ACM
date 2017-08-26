#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 10001

int n, fa[MAXN], qA, qB;
int indegree[MAXN];
int vis[MAXN];
vector<int> map[MAXN];
int ancestor[MAXN];

int find(int x) { return x != fa[x] ? fa[x] = find(fa[x]) : fa[x]; }

void merge(int x,int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    fa[fy] = fx;
}

void Tarjan(int u) {
    ancestor[u] = u;
    for (int i = 0; i < map[u].size(); i++) {
        Tarjan(map[u][i]);
        merge(u, map[u][i]);
        ancestor[find(u)] = u;
    }
    vis[u] = 1;
    if (qB == u) swap(qA, qB);
    if (qA == u && vis[qB]) {
        printf("%d\n", ancestor[find(qB)]);
        return;
    }
}

int main() {
    int t, i, u, v;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for(i = 0; i <= n; i++) {
            fa[i] = i;
            indegree[i] = 0;
            vis[i] = 0;
            map[i].clear();
        }
        for(i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            map[u].push_back(v);
            indegree[v]++;
        }
        scanf("%d%d", &qA, &qB);
        for (i = 1; i <= n; i++) {
            if(indegree[i] == 0) {
                Tarjan(i);
                break;
            }
        }
    }
    return 0;
}