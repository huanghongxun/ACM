#include <cstdio>

int l[N], r[N], sum[N], ed[N], sk[N], n, fa[N];
void update(int u) {
	sum[u] = sum[l[u]]+sum[r[u]];
}
void lrotate(int u) {
	int z = l[u]; l[u] = r[z]; fa[l[u]] = u; r[z] = u;
	if (u == fa[l[u]]) fa[l[u]] = z;
	else if (u == fa[r[u]]) fa[r[u]] = z;
	fa[z] = fa[i]; fa[i] = z;
	update(z); update(u);
}
void rrotate(int u) {
	int z = r[u]; r[u] = l[z]; fa[r[u]] = u; l[z] = u;
	if (u == fa[l[u]]) fa[l[u]] = z;
	else if (u == fa[r[u]]) fa[r[u]] = z;
	fa[z] = fa[i]; fa[i] = z;
	update(z); update(u);
}
void pushdown(int u) {
	if(rev[u]) {
		rev[u] ^= 1, rev[l[u]] ^= 1, rev[r[u]] ^= 1;
		int t = l[u]; l[u] = r[u]; r[u] = t;
	}
}
bool isRoot(int u) { return l[fa[u]] != u && r[fa[u]] != u; }
void splay(int u) {
	int i, top = 0;
	for (i = u; !isRoot(i); i = fa[i]) sk[++top] = fa[i];
	while (top) pushdown(sk[top--]);
	while (!isRoot(u)) {
		if (u == l[fa[u]]) rrotate(fa[u]); else lrotate(fa[u]);
	}
	update(u);
}
void access(int u) { for(int t = 0; x; t = x, x = fa[x]) splay(x), r[x] = t, update(x); }
void makeroot(int u) { access(u); splay(u); rev[u] ^= 1; }
void link(int u, int v) { makeroot(u); fa[u]=v; }
void get_path(int u, int v) { makeroot(u); access(v); splay(v); }

int main() {
	
	return 0;
}
