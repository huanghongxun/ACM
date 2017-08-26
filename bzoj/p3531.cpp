#include <cstdio>
#include <algorithm>
using namespace std;
int read() {
	int s=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;'0'<=ch&&ch<='9';ch=getchar())s=s*10+ch-'0';
	return s*f;
}
const int N = 100001, M = N * 2;
int son[N], fa[N], dep[N], pos[N], top[N], sz[N], n, m;
int head[N], next[N], to[N], cnt = 0, id = 0, seg = 0;
int lc[M], rc[M], sum[M], ma[M], root[N], c[N], w[N];

void add(int u, int v) {
	next[++cnt] = head[u]; head[u] = cnt; to[cnt] = v;
	next[++cnt] = head[v]; head[v] = cnt; to[cnt] = u;
}

void dfs1(int t) {
	sz[t] = 1; son[t] = 0;
	for (int i = head[t]; i; i = next[i])
		if (to[i] != fa[t]) {
			fa[to[i]] = t; dep[to[i]] = dep[t] + 1;
			dfs1(to[i]);
			sz[t] += sz[to[i]];
			if (sz[to[i]] > sz[son[t]]) son[t] = to[i];
		}
}

void dfs2(int x, int t) {
	pos[x] = ++id; top[x] = t;
	if (son[x]) dfs2(son[x], t);
	for (int i = head[x]; i; i = next[i])
		if (to[i] != son[x] && to[i] != fa[x])
			dfs2(to[i], to[i]);
}

int querySum(int t, int l, int r, int ql, int qr) {
	if (!t) return 0;
	if (l == ql && r == qr) return sum[t];
	int mid = l + r >> 1;
	if (qr <= mid) return querySum(lc[t], l, mid, ql, qr);
	else if (ql > mid) return querySum(rc[t], mid + 1, r, ql, qr);
	else return querySum(lc[t], l, mid, ql, mid) + querySum(rc[t], mid + 1, r, mid + 1, qr);
}

int queryMax(int t, int l, int r, int ql, int qr) {
	if (!t) return 0;
	if (l == ql && r == qr) return ma[t];
	int mid = l + r >> 1;
	if (qr <= mid) return queryMax(lc[t], l, mid, ql, qr);
	else if (ql > mid) return queryMax(rc[t], mid + 1, r, ql, qr);
	else return max(queryMax(lc[t], l, mid, ql, mid), queryMax(rc[t], mid + 1, r, mid + 1, qr));
}

void modify(int &t, int l, int r, int x, int k) {
	if (!t) t = ++seg;
	if (l == r) { ma[t] = sum[t] = k; return; }
	int mid = l + r >> 1;
	if (x <= mid) modify(lc[t], l, mid, x, k);
	else modify(rc[t], mid + 1, r, x, k);
	ma[t] = max(ma[lc[t]], ma[rc[t]]);
	sum[t] = sum[lc[t]] + sum[rc[t]];
}

int treeSum(int c, int x, int y) {
	int fx = top[x], fy = top[y], ans = 0;
	while (fx != fy) {
		if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y);
		ans += querySum(root[c], 1, n, pos[fx], pos[x]);
		x = fa[fx], fx = top[x];
	}
	if (dep[x] < dep[y]) swap(x, y);
	return ans + querySum(root[c], 1, n, pos[y], pos[x]);
}

int treeMax(int c, int x, int y) {
	int fx = top[x], fy = top[y], ans = 0;
	while (fx != fy) {
		if (dep[fx] < dep[fy]) swap(fx, fy), swap(x, y);
		ans = max(ans, queryMax(root[c], 1, n, pos[fx], pos[x]));
		x = fa[fx], fx = top[x];
	}
	if (dep[x] < dep[y]) swap(x, y);
	return max(ans, queryMax(root[c], 1, n, pos[y], pos[x]));
}

int main() {
	char ch[10];
	int i, x, y;
	n = read(); m = read();
	for (i = 1; i <= n; i++) w[i] = read(), c[i] = read();
	for (i = 1; i < n; i++) add(read(), read());
	dfs1(1); dfs2(1, 1);
	while (m--) {
		scanf("%s", ch);
		x = read(); y = read();
		switch (ch[1]) {
		case 'C':
			modify(root[c[x]], 1, n, pos[x], 0);
			modify(root[c[x] = y], 1, n, pos[x], w[x]);
			break;
		case 'W':
			modify(root[c[x]], 1, n, pos[x], w[x] = y);
			break;
		case 'S':
			printf("%d\n", treeSum(c[x], x, y));
			break;
		case 'M':
			printf("%d\n", treeMax(c[x], x, y));
			break;
		}
	}
	return 0;
}
