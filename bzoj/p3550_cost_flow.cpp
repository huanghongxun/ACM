#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define min(i,j) ((i)>(j)?(j):(i))
const int inf = 2147483647;
int read() {
    int s=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*f;
}
template<int N, int M>
class EdmondsKarp {
private:
    int h[N], v[M], w[M], p[M], c[M], cnt;
    int n, m, ans, s, t;
    int q[N*64], pre[N], dis[N];
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
};

int main() {
    const int N = 1201;
    static EdmondsKarp<N,40001> g;
    static int c[N];
    int n=read(),k=read(),ss=0,s=1,t=2*n+2,tt=t+1,i;
    FOR(i,1,3*n)c[i]=read();
    g.init(tt,ss,tt);
    g.add(ss,s,k,0); g.add(t,tt,k,0);
    FOR(i,1,n) g.add(s,i+1,1,-c[i]);
    FOR(i,n+1,2*n) g.add(i-n+1,i+1,1,-c[i]);
    FOR(i,n+1,2*n) g.add(i+1,t,1,-c[n+i]);
    FOR(i,s,t) g.add(i-1,i,k,0);
    printf("%d",-g.run());
    return 0;
}