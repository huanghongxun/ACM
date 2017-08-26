#include <cstdio>
#include <algorithm>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;i++)
using std::swap; using std::max;
int read() {
	int s = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
	return s * f;
}
const int N = 200001, M = N * 2;
int n, id = 0, cnt = 0;
int dep[N], son[N], sz[N], fa[N], top[N], pos[N], end[N];
int head[N], next[M], to[M], ma[M];

void add(int u, int v) {
	next[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
	next[++cnt] = head[v]; head[v] = cnt; to[cnt] = u;
}

void dfs1(int x) {
	son[x] = 0; sz[x] = 1;
	for (int i = head[x]; i; i = next[i])
		if (to[i] != fa[x]) {
			fa[to[i]] = x; dep[to[i]] = dep[x] + 1;
			dfs1(to[i]); sz[x] += sz[to[i]];
			if (sz[son[x]] < sz[to[i]]) son[x] = to[i];
		}
}

void dfs2(int x, int t) {
	top[x] = t; pos[x] = ++id;
	if (son[x]) dfs2(son[x], t);
	for (int i = head[x]; i; i = next[i])
		if (to[i] != son[x] && to[i] != fa[x])
			dfs2(to[i], to[i]);
	end[x] = id;
}

void modify(int t, int l, int r, int x, int v) {
	if (l == r) { ma[t] = v; return; }
	int mid = l + r >> 1;
	if (x <= mid) modify(t * 2, l, mid, x, v);
	else if (x > mid) modify(t * 2 + 1, mid + 1, r, x, v);
	ma[t] = max(ma[t * 2], ma[t * 2 + 1]);
}

int query(int t, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return ma[t];
	int mid = l + r >> 1;
	if (qr <= mid) return query(t * 2, l, mid, ql, qr);
	else if (ql > mid) return query(t * 2 + 1, mid + 1, r, ql, qr);
	else return max(query(t * 2, l, mid, ql, mid),
		query(t * 2 + 1, mid + 1, r, mid + 1, qr));
}

int treeQuery(int x, int y) {
	int fx = top[x], fy = top[y], ans = 0;
	while (fx != fy) {
		if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y);
		ans = max(ans, query(1, 1, n, pos[fx], pos[x]));
		x = fa[fx], fx = top[x];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return max(ans, query(1, 1, n, pos[x], pos[y]));
}

int main() {
	static int a[M], b[M], c[M];
	char ch[8];
	int i, x, y, z, t;
	t = read();
	while (t--) {
		n = read();
		memset(ma, 0, sizeof ma);
		memset(head, 0, sizeof head);
		FOR(i,2,n) a[i] = read(), b[i] = read(), c[i] = read(), add(a[i], b[i]);
		dfs1(1); dfs2(1, 1);
		FOR(i,2,n) {
			if (dep[a[i]] > dep[b[i]]) swap(a[i], b[i]);
			modify(1, 1, n, pos[b[i]], c[i]);
		}
		while (1) {
			scanf("%s", ch);
			if (ch[0] == 'C')
				x = read(), y = read(), modify(1, 1, n, pos[b[x]], y);
			else if (ch[0] == 'Q')
				x = read(), y = read(), printf("%d\n", treeQuery(x, y));
			else break;
		}
	}
	return 0;
}
