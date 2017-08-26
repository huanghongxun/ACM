#include <cstdio>
#include <cstring>
#define inf 2147483647
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define ll long long 
using namespace std;
ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x * f;
}
template<int N, int M>
class EdmondsKarp {
private:
    ll h[N], v[M], w[M], p[M], c[M], cnt;
    ll n, m, ans, s, t;
    ll q[N * 4], pre[N], dis[N];
    bool vis[M];
    bool spfa() {
    	memset(pre, -1, sizeof pre);
        int i, f = 0, r = 0;
        for(i = 0; i <= n; i ++)
            dis[i] = inf, vis[i] = 0;
        dis[s] = 0, q[r++] = s, vis[s] = 1;
        pre[s] = pre[t] = -1;
        while (f < r) {
            int u = q[f++];
            for(i = h[u]; i != -1; i = p[i]) {
                if(w[i] && dis[v[i]] > dis[u] + c[i]){
                    dis[v[i]] = dis[u] + c[i];
                    pre[v[i]] = i ^ 1;
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
        ll u, sum = inf;
        for(u = pre[t]; u >= 0; u = pre[v[u]])
            sum = sum > w[u ^ 1] ? w[u ^ 1] : sum;
        for(u = pre[t]; u >= 0; u = pre[v[u]]) {
            w[u] += sum;
            w[u^1] -= sum;
            ans += sum * c[u^1];
        }
    }
public:
    void init(ll o, ll a, ll b) {
        n = o, s = a, t = b, cnt = 0;
        memset(h,-1,sizeof(h));
    }

    void add(ll x, int y, ll ca, ll co) {
        v[cnt] = y, w[cnt] = ca, c[cnt] = co, p[cnt] = h[x], h[x] = cnt++;
        v[cnt] = x, w[cnt] = 0, c[cnt] = -co, p[cnt] = h[y], h[y] = cnt++;
    }

    ll run() {
        ans = 0;
        while(spfa()) end();
        return ans;
    }
};

ll c[1024];
ll build(int n, int k, ll *c) {
	int SS = 0, TT = 2 * n + 3, S = 1, T = 2 * n + 2, i; 
	EdmondsKarp<1024, 131072> *g = new EdmondsKarp<1024, 131072>();
	g->init(TT, SS, TT); 
    g->add(SS, S, k, 0);
    g->add(T, TT, k, 0);
    FOR(i, 2, n + 1) g->add(S, i, 1, -c[i - 1]);
    FOR(i, n + 2, 2 * n + 1) g->add(i - n, i, 1, -c[i - 1]);
    FOR(i, n + 2, 2 * n + 1) g->add(i, T, 1, -c[i - 1 + n]);
    FOR(i, 2, 2 * n + 2) g->add(i - 1, i, k, 0);
    return -g->run();
}

int main() {
    int n = read(), k = read();
    for(int i=1;i<=3*n;i++) c[i] = read();
    printf("%I64d", build(n, k, c));
    return 0;
}
