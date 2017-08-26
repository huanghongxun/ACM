#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
int sz[N], l[N], r[N], fa[N], sum[N], val[N], max[N], rev[N], sk[N];

void update(int x) {
	max[x] = std::max(std::max(max[l[x]], max[r[x]]), val[x]);
	sum[x] = sum[l[x]] + sum[r[x]] + val[x];
}

void pushdown(int x) {
	if (rev[x]) { rev[x] ^= 1, rev[l[x]] ^= 1, rev[r[x]] ^= 1, std::swap(l[x], r[x]); }
}

bool isRoot(int x) {
	return l[fa[x]] != x && r[fa[x]] != x;
}

void lrotate(int i) {
	int z = r[i]; r[i] = l[z]; fa[r[i]] = i; l[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z;
	else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z;
	update(i); update(z);
}

void rrotate(int i) {
	int z = l[i]; l[i] = r[z]; fa[l[i]] = i; r[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z;
	else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z;
	update(i); update(z);
}

void spaly(int x) {
	int top = 0;
	sk[++top] = x;
	for (int i = x; !isRoot(i); i = fa[i]) sk[++top] = fa[i];
	while (top) pushdown(sk[top--]);
	while (!isRoot(x))
		if (x == l[fa[x]]) rrotate(fa[x]);
		else lrotate(fa[x]);
	update(x);
}

void access(int x) { for(int t = 0; x; t = x, x = fa[x]) { spaly(x); r[x] = t; update(x); } }
void makeroot(int x) { access(x); spaly(x); rev[x] ^= 1; }
int query_sum(int x, int y) { makeroot(x); access(y); spaly(y); return sum[y]; }
int query_max(int x, int y) { makeroot(x); access(y); spaly(y); return max[y]; }
void modify(int x, int v) { access(x); val[x] = v; update(x); }
int h[N], p[N], to[N], cnt = 0;
void add(int a, int b) { p[cnt] = h[a], to[cnt] = b, h[a] = cnt++; }
void dfs(int x) {
	for (int i = h[x]; i != -1; i = p[i])
		if (to[i] != fa[x])
			fa[to[i]] = x, dfs(to[i]);
}

int main() {
	int n, u, v, i, q;
	char ch[8];
	scanf("%d", &n);
	std::fill(h,h+n+2,-1);
	std::fill(rev,rev+n+2,0);
	max[0] = -2147483647;
	for (i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs(1);
	for (i = 1; i <= n; i++) {
		scanf("%d", &u);
		val[i] = max[i] = sum[i] = u;
	}
	scanf("%d", &q);
	for(; q>0; q--) {
		scanf("%s%d%d", ch, &u, &v);
		if (ch[1] == 'M') printf("%d\n", query_max(u, v));
		else if (ch[1] == 'S') printf("%d\n", query_sum(u, v));
		else modify(u, v);
	}
	return 0;
}
