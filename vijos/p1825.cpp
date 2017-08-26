#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 2000
#define M 200000
#define inf 0x7ffffff

class EdmondsKarp {
private:
    int h[N], v[M], w[M], p[M], c[M], cnt;
    int n, m, ans, s, t;
    int q[N*5], pre[N], dis[N];
    bool vis[M];
    bool spfa() {
        int i, f = 0, r = 0;
        for(i = 0; i <= n; i ++) {
            dis[i] = inf;
            vis[i] = 0;
        }
        dis[s] = 0, q[r++] = s, vis[s] = 1;
        pre[s] = pre[t] = -1;
        while (f < r) {
            int u = q[f++];
            for(i = h[u]; i != -1; i = p[i]) {
                if(w[i] && dis[v[i]] > dis[u] + c[i]){
                    dis[v[i]] = dis[u] + c[i];
                    pre[v[i]] = i^1;
                    if(!vis[v[i]]) {
                        vis[v[i]] = 1;
                        q[r++] = v[i];
                    }
                }
            }
            vis[u] = 0;
        }
        if(dis[t] == inf) return 0;
        return 1;
    }

    void end() {
        int u, sum = inf;
        for(u = pre[t]; u >= 0; u = pre[v[u]]) {
            sum = min(sum, w[u^1]);
        }
        for(u = pre[t]; u >= 0; u = pre[v[u]]) {
            w[u] += sum;
            w[u^1] -= sum;
            ans += sum * c[u^1];
        }
    }
public:
    void init(int o, int a, int b) {
        n = o, s = a, t = b, cnt = 0;
        memset(h,-1,sizeof(h));
    }

    void add(int x, int y, int ca, int co) {
        v[cnt] = y, w[cnt] = ca, c[cnt] = co, p[cnt] = h[x], h[x] = cnt++;
        v[cnt] = x, w[cnt] = 0, c[cnt] = -co, p[cnt] = h[y], h[y] = cnt++;
    }

    int run() {
        ans = 0;
        while(spfa()) end();
        return ans;
    }
} g;

int main()
{
    int S, T, n, m, i, x, y, z, a;
    scanf("%d%d",&n,&m);
    S=0;T=n+2;
    g.init(T,S,T);
    for (i=1;i<=n;i++) {
        scanf("%d",&a);
        g.add(S, i, a, 0);
        g.add(i+1, T, a, 0);
        g.add(i+1, i, inf, 0);
    }
    for (i=1;i<=m;i++) {
        scanf("%d%d%d",&x,&y,&z);
        g.add(x,y+1,inf,z);
    }
    printf("%d", g.run());
    return 0;
}