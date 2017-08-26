#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
int sz[N], root[N], l[N], r[N], fa[N], sum[N], key[N];

void update(int x) {
	sz[x] = sz[l[x]] + sz[r[x]] + 1;
	sum[x] = sum[l[x]] + sum[r[x]] + key[x];
}

void lrotate(int i) {
	int z = r[i]; r[i] = l[z]; fa[r[i]] = i; l[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z;
	else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z;
	root[z] ^= root[i];
	root[i] ^= root[z];
	update(i); update(z);
}

void rrotate(int i) {
	int z = l[i]; l[i] = r[z]; fa[l[i]] = i; r[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z;
	else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z;
	root[z] ^= root[i];
	root[i] ^= root[z];
	update(i); update(z);
}

void splay(int i) {
	while (!root[i])
		if (i == l[fa[i]]) rrotate(fa[i]);
		else lrotate(fa[i]);
	update(i);
}

void access(int x) {
	splay(x);
	while (fa[x] != 0) {
	    int y = fa[x];
	    splay(y);
	    root[r[y]] = 1;
	    root[x] = 0;
	    r[y] = x;
	    update(y);
	    splay(x);
	}
}

int query_sum(int x, int y) {
	access(y); access(x);
	splay(y); splay(fa[y]);
	return sum[y] + sum[r[fa[y]]];
}

int find(int t, int k) {
	while (t != 0) {
		update(t);
		if (sz[l[t]] + 1 == k) return t;
		if (sz[l[t]] >= k) t = l[t];
		else k -= sz[l[t]]+1, t = r[t];
	}
	return t;
}

int query_kth(int x, int y, int k) {
	access(y); access(x);
	splay(y); splay(fa[y]);
	if(sz[fa[y]] < k) return find(y, k-sz[fa[y]]);
	else return find(fa[y], sz[fa[y]]-k+1);
}

int h[N], w[N], p[N], to[N], cnt = 0;

void add(int a, int b, int c) {
	p[cnt] = h[a];
	w[cnt] = c;
	to[cnt] = b;
	h[a] = cnt++;
}

void dfs(int x, int f) {
	int i, v;
	for (i = h[x]; i != -1; i = p[i])
		if ((v = to[i]) != f)
			sum[v] = key[v] = w[i], fa[v] = x, dfs(v, x);
}

int main() {
	int i, n, a, b, c, kase;
	char ch[10];
	scanf("%d", &kase);
	while(kase--) {
		scanf("%d", &n);
		std::fill(h, h+n+2, -1);
		std::fill(root, root+n+2, 1);
		std::fill(sz, sz+n+2, 0);
		for (i = 1; i < n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c); add(b, a, c);
		}
		dfs(1, 0);
		while(1) {
			scanf("%s", ch);
			if (ch[1] == 'O') break;
			if (ch[1] == 'T') { scanf("%d%d%d", &a, &b, &c); printf("%d\n", query_kth(a, b, c)); }
			if (ch[1] == 'I') { scanf("%d%d", &a, &b); printf("%d\n", query_sum(a, b)); }
		}
	}
	return 0;
}
