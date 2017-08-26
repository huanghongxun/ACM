#include <cstdio>
#include <algorithm>
#define N 20005

int h[N], p[N], to[N], w[N], u[N], v[N], c[N], edge = 0, cnt = 0;
int dep[N], fa[N], son[N], top[N], num[N], key[N], a[N], L[N], R[N], max[N], sz[N];
void add(int u, int v, int c) {
	p[edge] = h[u], to[edge] = v, w[edge] = c, h[u] = edge++;
	p[edge] = h[v], to[edge] = u, w[edge] = c, h[v] = edge++;
}
void dfs(int u) {
	sz[u] = 1, son[u] = 0;
	for(int i = h[u]; i != -1; i = p[i]) {
		int v = to[i];
		if (v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
			if (sz[v] > sz[son[u]]) son[u] = v;
			sz[u] += sz[v];
		}
	}
}
void dfs2(int u, int t) {
	num[u] = ++cnt;
	a[cnt] = key[u];
	top[u] = t;
	if (son[u]) dfs2(son[u], top[u]);
	for (int i = h[u]; i != -1; i = p[i]) {
		int v = to[i];
		if(v != son[u] && v != fa[u]) dfs2(v, v);
	}
}
void build(int t, int l, int r) {
	L[t] = l, R[t] = r;
	if (l == r) {
		max[t] = a[l];
		return;
	}
	int m = l+r>>1;
	build(t*2, l, m); build(t*2+1, m+1, r);
	max[t] = std::max(max[t*2], max[t*2+1]);
}
void modify(int t, int x, int c) {
	if (L[t] == x && R[t] == x) {
		max[t] = c;
		return;
	}
	int m = (L[t]+R[t])/2;
	if (x <= m) modify(t*2,x,c);
	else modify(t*2+1,x,c);
	max[t] = std::max(max[t*2], max[t*2+1]);
}
int get_max(int t, int l, int r) {
	if (l <= L[t] && R[t] <= r) return max[t];
	int m = (L[t]+R[t])/2;
	if (m>=r) return get_max(t*2,l,r);
	else if(m<l) return get_max(t*2+1,l,r);
	else return std::max(get_max(t*2,l,m),get_max(t*2+1,m+1,r));
}
int query_max(int l, int r) {
	int ans = -2147483647;
	while (top[l] != top[r]) {
		if (dep[top[l]] < dep[top[r]]) std::swap(l, r);
		ans = std::max(ans, get_max(1, num[top[l]], num[l]));
		l = fa[top[l]];
	}
	if (dep[l] > dep[r]) std::swap(l, r);
	if (l != r) ans = std::max(ans, get_max(1, num[l], num[r]));
	return ans;
}
int main() {
	int t, a, b, i, n; char op[10];
	scanf("%d", &t);
	while(t--) {
		fa[1] = dep[1] = edge = cnt = 0;
		scanf("%d", &n);
		std::fill(h+1, h+1+n, -1);
		for (i = 1; i < n; i++) {
			scanf("%d%d%d", &u[i], &v[i], &c[i]);
			add(u[i],v[i],c[i]);
		}
		dfs(1);
		for (i = 1; i < n; i++) {
			if (dep[u[i]] > dep[v[i]])
				key[u[i]] = c[i];
			else
				key[v[i]] = c[i];
		}
		dfs2(1,1);
		build(1, 1, cnt);
		while (scanf("%s", op)) {
			if(op[0] == 'Q') {
				scanf("%d%d", &a, &b);
				printf("%d\n", query_max(a, b));
			} else if(op[0] == 'D') {
				break;
			} else if(op[0] == 'C') {
				scanf("%d%d", &a, &b);
				if (dep[u[a]] > dep[v[a]])
					modify(1, num[u[a]], b);
				else
					modify(1, num[v[a]], b);
			}
		}
	}

	return 0;
}
