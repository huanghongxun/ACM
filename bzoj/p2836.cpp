#include <cstdio>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;i++)
typedef long long ll;
using std::swap;
ll read() {
	ll s = 0; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
	return s;
}
const int N = 200001, M = N * 2;
int n, id = 0, cnt = 0;
int dep[N], son[N], sz[N], fa[N], top[N], pos[N], end[N];
int head[N], next[M], to[M];
ll sum[M], lazy[M];

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

void update(int t, int l, int r, ll v) {
    sum[t] += (r - l + 1) * v; lazy[t] += v;
}

void pushdown(int t, int l, int r) {
	int mid = l + r >> 1; 
	update(t * 2, l, mid, lazy[t]);
	update(t * 2 + 1, mid + 1, r, lazy[t]);
	lazy[t] = 0;
}

void modify(int t, int l, int r, int ql, int qr, ll plus) {
	if (l == ql && r == qr) { update(t, l, r, plus); return; }
	pushdown(t, l, r);
	int mid = l + r >> 1;
	if (qr <= mid) modify(t * 2, l, mid, ql, qr, plus);
	else if (ql > mid) modify(t * 2 + 1, mid + 1, r, ql, qr, plus);
	else modify(t * 2, l, mid, ql, mid, plus),
		modify(t * 2 + 1, mid + 1, r, mid + 1, qr, plus);
	sum[t] = sum[t * 2] + sum[t * 2 + 1];
}

ll query(int t, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return sum[t];
	pushdown(t, l, r);
	int mid = l + r >> 1;
	if (qr <= mid) return query(t * 2, l, mid, ql, qr);
	else if (ql > mid) return query(t * 2 + 1, mid + 1, r, ql, qr);
	else return query(t * 2, l, mid, ql, mid) +
		query(t * 2 + 1, mid + 1, r, mid + 1, qr);
}

void treeModify(int x, int y, ll c) {
	int fx = top[x], fy = top[y];
	while (fx != fy) {
		if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y);
		modify(1, 1, n, pos[fx], pos[x], c);
		x = fa[fx], fx = top[x];
	}
	if (dep[x] > dep[y]) swap(x, y);
	modify(1, 1, n, pos[x], pos[y], c);
}

int main() {
	int i, x, y, q; ll z; char ch[8];
	n = read();
	FOR(i,2,n) add(read()+1, read()+1);
	q = read();
	dfs1(1); dfs2(1, 1);
	while (q--) {
		scanf("%s", ch);
		if (ch[0] == 'A') { // Add
			x = read()+1, y = read()+1, z = read();
			treeModify(x, y, z);
		} else { // Query
			x = read()+1;
			printf("%lld\n", query(1, 1, n, pos[x], end[x]));
		}
	}
	return 0;
}
