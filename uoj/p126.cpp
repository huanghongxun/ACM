#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
const int N = 100005, M = N * 2;
const ll inf = 1e18;

int cnt = 0, m = 0;
ll low = 0, ans = inf, now, tot;
ll pre[N], suf[N], tpre[N], tsuf[N], w[M], dis[N], far[N];
int head[N], next[M], to[M], fa[N], vis[N], in[N], cir[N];

void add(int u, int v, ll l) {
	next[cnt] = head[u], to[cnt] = v, w[cnt] = l, head[u] = cnt++;
}

void dfs(int u) {
	vis[u] = 1;
	for (int i = head[u]; i != -1; i = next[i])
		if (to[i] != fa[u]) {
			int v = to[i];
			if (!vis[v]) {
				fa[v] = u; dfs(v); continue;
			}
			if (in[u]) continue;
			for (int j = u; j != v; j = fa[j]) {
				in[j] = 1;
				cir[++m] = j;
			}
			in[v] = 1; cir[++m] = v;
		}
}

pair<ll, int> farthest(int u, int from = -1) {
	pair<ll, int> ret(0, u);
	for (int i = head[u]; i != -1; i = next[i])
		if (to[i] != from && !in[to[i]]) {
			pair<ll, int> tmp = farthest(to[i], u);
			tmp.first += w[i];
			ret = max(ret, tmp);
		}
	return ret;
}

int main() {
	int x, y, z, i, n;
	memset(head, -1, sizeof head);
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
	}

	dfs(1);

	FOR(i,1,m) {
		in[cir[i]] = 0;
		pair<ll, int> tmp = farthest(cir[i]);
		far[cir[i]] = tmp.first;
		low = max(low, farthest(tmp.second).first);
		in[cir[i]] = 1;
	}

	FOR(i,2,m)
		for (int j = head[cir[i]]; j != -1; j = next[j])
			if (to[j] == cir[i - 1]) {
				dis[cir[i]] = w[j] + dis[cir[i - 1]];
				break;
			}

	for (i = head[cir[1]]; i != -1; i = next[i])
		if (to[i] == cir[m]) {
			tot = w[i] + dis[cir[m]];
			break;
		}

	pre[  0  ] = -inf;
	now = -inf;
	FOR (i,1,m) {
		pre[i] = max(pre[i - 1], now + dis[cir[i]] + far[cir[i]]);
		now = max(now, far[cir[i]] - dis[cir[i]]);
	}

	suf[m + 1] = -inf;
	now = -inf;
	FORD(i,m,1) {
		suf[i] = max(suf[i + 1], now - dis[cir[i]] + far[cir[i]]);
		now = max(now, far[cir[i]] + dis[cir[i]]);
	}

	tpre[  0  ] = -inf;
	FOR (i,1,m) tpre[i] = max(tpre[i - 1], far[cir[i]] + dis[cir[i]]);

	tsuf[m + 1] = -inf;
	FORD(i,m,1) tsuf[i] = max(tsuf[i + 1], far[cir[i]] - dis[cir[i]]);

	FOR(i,1,m) ans = min(ans, max(max(pre[i], suf[i + 1]), tpre[i] + tsuf[i + 1] + tot));
	ans = max(min(ans, pre[m]), low);
	printf("%.1lf\n", (double)ans / 2);

	return 0;
}