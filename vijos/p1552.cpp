#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define inf 0x7ffffff
using namespace std;
#define M 10005
#define N 2500

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
int main() {
	int n, a, b, fa, fb, f, x, i, j;
	scanf("%d%d%d%d%d%d", &n, &a, &b, &f, &fa, &fb);
	int S = 0, T = n * 2 + 1;
	g.init(T, S, T);
	g.add(S, 1, inf, f);
	for (i = 1; i <= n; i++) {
		scanf("%d", &x);
		//g.add(S, i, x, f);
		g.add(S, n + i, x, 0);
		g.add(i, T, x, 0);
	}
	for (i = 1; i <= n; i++){
		for (j = i + a + 1; j <= n; j++) {
			g.add(n + i, j, inf, fa);
		}
		for (j = i + b + 1; j <= n; j++) {
			g.add(n + i, j, inf, fb);
		}
	}
	printf("%d", g.run());
	return 0;
}
