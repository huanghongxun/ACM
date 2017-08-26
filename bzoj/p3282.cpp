#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 300005
int l[N], r[N], fa[N], sum[N], val[N], rev[N]={0}, sk[N], n;
void update(int x) { sum[x] = sum[l[x]] ^ sum[r[x]] ^ val[x]; }
void pushdown(int x) { if (rev[x]) rev[x] ^= 1, rev[l[x]] ^= 1, rev[r[x]] ^= 1, std::swap(l[x], r[x]); }
bool isRoot(int x) { return l[fa[x]]!=x&&r[fa[x]]!=x; }
void lrotate(int i) {
	int z = r[i]; r[i] = l[z]; fa[r[i]] = i; l[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z; else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z; update(i); update(z);
}
void rrotate(int i) {
	int z = l[i]; l[i] = r[z]; fa[l[i]] = i; r[z] = i;
	if (i == l[fa[i]]) l[fa[i]] = z; else if (i == r[fa[i]]) r[fa[i]] = z;
	fa[z] = fa[i]; fa[i] = z; update(i); update(z);
}
void splay(int x) {
	int top = 0; sk[++top] = x;
	for (int i = x; !isRoot(i); i = fa[i]) sk[++top] = fa[i];
	while (top) pushdown(sk[top--]);
	while (!isRoot(x)) if (x == l[fa[x]]) rrotate(fa[x]); else lrotate(fa[x]);
	update(x);
}
void access(int x) { for(int t = 0; x; t = x, x = fa[x]) splay(x), r[x] = t, update(x); }
void makeroot(int x) { access(x); splay(x); rev[x] ^= 1; }
int find(int x) { access(x); splay(x); while (l[x]) x = l[x]; return x; }
void link(int x, int y) { makeroot(x); fa[x] = y; }
void cut(int x, int y) { makeroot(x); access(y); splay(y); if(l[y]==x) l[y]=fa[x]=0; }
int main() {
	int x, y, i, q, op;
	scanf("%d%d", &n, &q);
	for (i = 1; i <= n; i++) scanf("%d", &val[i]);
	for(; q>0; q--) {
		scanf("%d%d%d", &op, &x, &y);
		switch(op) {
		case 0: makeroot(x); access(y); splay(y); printf("%d\n", sum[y]); break;
		case 1: if (find(x) != find(y)) link(x, y); break;
		case 2: if (find(x) == find(y)) cut(x, y); break;
		case 3: access(x); splay(x); val[x] = y; update(x); break;
		}
	}
	return 0;
}