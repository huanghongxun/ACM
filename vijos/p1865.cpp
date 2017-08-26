#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200005
int sz[N], root[N], l[N], r[N], fa[N], sum[N], key[N], f[N], val[N], mx[N], rev[N];
int n;
struct Edge { int u, v, a, b; } e[N];
bool operator < (const Edge &a, const Edge &b) { return a.a < b.a; }

void pushup(int x) {
	mx[x] = x;
	if (val[mx[l[x]]] > val[mx[x]]) mx[x] = mx[l[x]];
	if (val[mx[r[x]]] > val[mx[x]]) mx[x] = mx[r[x]];
}

void pushdown(int x) {
	if (rev[x]) {
		rev[x] = 0, rev[l[x]] ^= 1, rev[r[x]] ^= 1;
		swap(r[x], l[x]);
	}
}

void lrotate(int i) {
	int z = r[i]; r[i] = l[z]; fa[r[i]] = i; l[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z;
	else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z;
	root[z] ^= root[i];
	root[i] ^= root[z];
	pushup(i); pushup(z);
}

void rrotate(int i) {
	int z = l[i]; l[i] = r[z]; fa[l[i]] = i; r[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z;
	else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z;
	root[z] ^= root[i];
	root[i] ^= root[z];
	pushup(i); pushup(z);
}

void splay(int i) { while (!root[i]) if (i == l[fa[i]]) rrotate(fa[i]); else lrotate(fa[i]); }
void access(int x) { for(int t = 0; x; ) { splay(x); r[x] = t; t = x; x = fa[x]; } }
void makeroot(int x) { access(x); splay(x); rev[x] ^= 1; }
void link(int x, int y) { makeroot(x); fa[x] = y; }
void cut(int x, int y) { makeroot(x); access(y); splay(y); l[y] = fa[x] = 0; }
int query(int x, int y) { makeroot(x); access(y); splay(y); return mx[y]; }
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void solve(int k) {
	int u = e[k].u, v = e[k].v, w = e[k].b;
	int t = query(u, v);
	if (w < val[t]) {
		cut(e[t-n].u,t); cut(e[t-n].v,t);
		link(u,k+n); link(v,k+n);
	}
}

int main() {
	int m, i, ans = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) f[i] = i;
	for (i = 1; i <= m; i++) scanf("%d%d%d%d", &e[i].u, &e[i].v, &e[i].a, &e[i].b);
	sort(e+1,e+1+m);
	for (i = 1; i <= m; i++) val[n+i]=e[i].b, mx[n+i]=n+i;
	for (i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].b;
		int p = find(u), q = find(v);
		if (p != q) { f[p] = q; link(i, n+i); link(v, n+i); }
		else solve(i);
		if (find(1) == find(n)) ans = min(ans, val[query(1, n)] + e[i].a);
	}

	return 0;
}
