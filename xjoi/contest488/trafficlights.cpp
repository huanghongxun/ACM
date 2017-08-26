#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;i++)
typedef long long ll;
int read() {
    int s=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
    return s*f;
}
#define M 2097152
#define N 524288
int head[N], next[M], to[M], w[M], k[M], l[M], r[M], cnt = 0;
void add(int a, int b, int c, int k, int l, int r) {
    next[cnt] = head[a]; to[cnt] = b; w[cnt] = c; ::k[cnt] = k; ::l[cnt] = l; ::r[cnt] = r; head[a] = cnt++;
    next[cnt] = head[b]; to[cnt] = a; w[cnt] = c; ::k[cnt] = k; ::l[cnt] = l; ::r[cnt] = r; head[b] = cnt++;
}
ll calc(ll dis, ll d, int k, int l, int r) {
    ll ans = 0; int time = dis % k;
    if (l <= time && time <= r) {
        if (d <= r - time + 1) return d;
        else d -= r - time + 1, ans += k - time + l;
    } else ans += (l - time + k) % k;
    ll a = (d - 1) / (r - l + 1), b = d - a * (r - l + 1);
    return ans + k * a + b;
}

int main(){
    int n, m, i, a, b, c, d, e, f, t;
    n = read(); m = read();
    memset(head, -1, sizeof head);
    FOR(i,1,m) {
        a=read();b=read();c=read();d=read();e=read();f=read();
        add(a,b,c,d,e,f);
    }
    static ll dis[N];
    static ll q[N * 8];
    static bool vis[N] = {0};
    memset(dis, 127, sizeof dis);
    f = 0, t = 0;
    q[t++] = 1; vis[1] = 1; dis[1] = 0;
    while (f < t) {
        int u = q[f++];
        for (int i = head[u]; i != -1; i = next[i]) {
            ll d = calc(dis[u], w[i], k[i], l[i], r[i]);
            if (dis[to[i]] > dis[u] + d) {
                dis[to[i]] = dis[u] + d;
                if (!vis[to[i]]) {
                    vis[to[i]] = 1; q[t++] = to[i];
                }
            }
        }
        vis[u] = 0;
    }
    FOR(i,1,n) printf("%lld\n", dis[i]);
    return 0;
}