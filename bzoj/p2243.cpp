#include <cstdio>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define rep(i,j,k) for(i=j;i<k;i++)
using namespace std;
typedef long long ll;
ll read() {
	ll s=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;'0'<=ch&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*f;
}

const int N = 100005;

struct Line {
	int s, lc, rc;
	Line operator & (const Line &b) const {
		return (Line) { s + b.s - (rc == b.lc), lc, b.rc }; 
	}
} nil;

Line val[N * 4], lazy[N * 4];

int cnt = 0, tot = 0, n, m;
int head[N], fa[N], son[N], dep[N], top[N], pos[N], sz[N], next[N*2], to[N*2], c[N], col[N];

void add(int u, int v) {
	next[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
	next[++cnt] = head[v]; head[v] = cnt; to[cnt] = u;
}

void dfs1(int x) {
	sz[x] = 1; son[x] = 0;
	for (int i = head[x]; i; i = next[i])
		if (to[i] != fa[x]) {
			fa[to[i]] = x; dep[to[i]] = dep[x] + 1;
			dfs1(to[i]);
			if (sz[to[i]] > sz[son[x]]) son[x] = to[i];
			sz[x] += sz[to[i]];
		}
}

void dfs2(int x, int t) {
	col[pos[x] = ++tot] = c[x]; top[x] = t;
	if (son[x] != 0) dfs2(son[x], t);
	for (int i = head[x]; i; i = next[i])
		if (to[i] != son[x] && to[i] != fa[x])
			dfs2(to[i], to[i]);
}

Line build(int t, int l, int r) {
	if (l == r) return val[t] = (Line) { 1, col[l], col[r] };
	int mid = l + r >> 1; 
	return val[t] = build(t * 2, l, mid) & build(t * 2 + 1, mid + 1, r);
}

void pushdown(int t) {
	if (lazy[t].s) {
		val[t * 2] = val[t * 2 + 1] = lazy[t * 2] = lazy[t * 2 + 1] = lazy[t];
		lazy[t] = nil;
	}
}

void modify(int t, int l, int r, int ql, int qr, const Line &x) {
	if (l == ql && r == qr) {
		val[t] = lazy[t] = x;
		return;
	}
	pushdown(t);
	int mid = l + r >> 1;
	if (qr <= mid) modify(t * 2, l, mid, ql, qr, x);
	else if (ql > mid) modify(t * 2 + 1, mid + 1, r, ql, qr, x);
	else modify(t * 2, l, mid, ql, mid, x), modify(t * 2 + 1, mid + 1, r, mid + 1, qr, x);
	val[t] = val[t * 2] & val[t * 2 + 1];
}

Line query(int t, int l, int r, int ql, int qr) {
	if (l == ql && r == qr) return val[t];
	pushdown(t);
	int mid = l + r >> 1;
	if (qr <= mid) return query(t * 2, l, mid, ql, qr);
	else if (ql > mid) return query(t * 2 + 1, mid + 1, r, ql, qr);
	else return query(t * 2, l, mid, ql, mid) & query(t * 2 + 1, mid + 1, r, mid + 1, qr);
}

int taskQ(int x, int y) {
	Line lx = nil, ly = nil;
	int fx = top[x], fy = top[y];
	while (fx != fy) {
		if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y), swap(lx, ly);
		lx = query(1, 1, n, pos[fx], pos[x]) & lx;
		x = fa[fx], fx = top[x];
	}
	if (dep[x] < dep[y]) swap(x, y), swap(lx, ly);
	lx = query(1, 1, n, pos[y], pos[x]) & lx;
	return lx.s + ly.s - (lx.lc == ly.lc);
}

void taskC(int x, int y, int colour) {
	Line l = (Line) { 1, colour, colour };
	int fx = top[x], fy = top[y];
	while (fx != fy) {
		if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y);
		modify(1, 1, n, pos[fx], pos[x], l);
		x = fa[fx], fx = top[x];
	}
	if (dep[x] > dep[y]) swap(x, y);
	modify(1, 1, n, pos[x], pos[y], l);
}

int main() {
	int i, x, y, z; char ch[5];
	nil = (Line) { 0, 0, 0 };
	n = read(), m = read();
	FOR(i,1,n) c[i]=read()+1;
	rep(i,1,n) add(read(),read());
	dfs1(1); dfs2(1, 1); build(1, 1, n);
	FOR(i,1,m) {
		scanf("%s", ch);
		if (ch[0] == 'Q') {
			x = read(), y = read();
			printf("%d\n", taskQ(x, y));
		} else {
			x = read(), y = read(), z = read() + 1;
			taskC(x, y, z);
		}
	}
	return 0;
}