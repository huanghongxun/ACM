#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 128, M = 16384, INF = 0x7f7f7f7f;
int h[N], p[M], v[M], w[M], cnt = 0;
int vis[N], inq[N], dis[N], n;

void add(int a, int b, int c) {
    p[++cnt] = h[a]; v[cnt] = b; w[cnt] = c; h[a] = cnt;
}

bool spfa(int src) {
    int i, u;
    queue<int> q;
    memset(inq, 0, sizeof inq);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x7f, sizeof dis);
    dis[src] = 0; q.push(src); vis[src] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (i = h[u]; i; i = p[i])
            if (dis[v[i]] > dis[u] + w[i]) {
                dis[v[i]] = dis[u] + w[i];
                if (!vis[v[i]]) {
                    q.push(v[i]);
                    if (++inq[v[i]] > n) return false;
                    vis[v[i]] = 1;
                }
            }
        vis[u] = 0;
    }
    return true;
}

int main() {
    int a, b, m, d, i;
    char prep[8];
    while (scanf("%d%d", &n, &m) == 2 && n != 0) {
        memset(h, 0, sizeof h);
        cnt = 0;

        while (m--) {
            scanf("%*s%d%*s%s", &a, prep);
            if (prep[0] == 'a') { // at
                scanf("%*s%d%*s%*s%*s%*s%d", &d, &b); // least
                add(a, b, -d);
            } else { // within
                scanf("%d%*s%*s%*s%*s%*s%*s%*s%d", &d, &b);
                add(b, a, d);
            }
            add(a, b, 0);
        }

        FOR(i,1,n) add(0, i, 0);
        
        if (!spfa(0)) puts("Impossible.");
        else {
            int mi = INF;
            FOR(i,1,n) if (mi > dis[i]) mi = dis[i];
            FOR(i,1,n) printf("%d%c", dis[i] - mi + 1, i == n ? '\n' : ' ');
        }
    }

    return 0;
}