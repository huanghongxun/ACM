#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
int sz[N], l[N], r[N], fa[N], val[N], max[N], rev[N], sk[N], min[N], neg[N], ed[N], n;

void update(int x) {
	max[x] = std::max(max[l[x]], max[r[x]]), min[x] = std::min(min[r[x]], min[l[x]]);
	if(x > n) max[x] = std::max(max[x], val[x]), min[x] = std::min(min[x], val[x]);
}

void reverse(int y) {
	std::swap(max[y], min[y]);
	max[y] = -max[y]; min[y] = -min[y];
	neg[y] ^= 1; val[y] = -val[y];
}

void pushdown(int x) {
	if (neg[x]) {
		neg[x] = 0;
		if(l[x]) reverse(l[x]);
		if(r[x]) reverse(r[x]);
	}
	if (rev[x]) {
		rev[x] ^= 1, rev[l[x]] ^= 1, rev[r[x]] ^= 1, std::swap(l[x], r[x]);
	}
}

bool isRoot(int x) {
	return l[fa[x]]!=x&&r[fa[x]]!=x;
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

void splay(int x) {
	int top = 0;
	sk[++top] = x;
	for (int i = x; !isRoot(i); i = fa[i]) sk[++top] = fa[i];
	while (top) pushdown(sk[top--]);
	while (!isRoot(x))
		if (x == l[fa[x]]) rrotate(fa[x]);
		else lrotate(fa[x]);
	update(x);
}

void access(int x) {
	for(int t = 0; x; t = x, x = fa[x]) {
		splay(x); r[x] = t; update(x);
	}
}

void makeroot(int x) {
	access(x); splay(x); rev[x] ^= 1;
}

void get_path(int x, int y) {
	makeroot(x); access(y); splay(y);
}

void link(int x, int y) {
	makeroot(x); fa[x] = y;
} 

int main() {
	int kase;
	scanf("%d", &kase);
	while(kase--) {
		int u, v, i, q;
		char ch[8];
		scanf("%d", &n);
		int id = n;
		std::fill(rev,rev+n+2,0);
		std::fill(neg,neg+n+2,0);
		std::fill(fa,fa+n+2,0);
		std::fill(l,l+n+2,0);
		std::fill(r,r+n+2,0);
		std::fill(val,val+n+2,0);
		std::fill(max,max+n+2,-2147483647);
		std::fill(min,min+n+2,2147483647);
		for (i = 1; i < n; i++) {
			scanf("%d%d%d", &u, &v, &q);
			ed[i] = ++id;
			link(u, id); link(v, id);
			val[id] = max[id] = min[id] = q;
		}
		
		for(;;) {
			scanf("%s", ch);
			if (ch[0] == 'D') break;
			scanf("%d%d", &u, &v);
			if (ch[0] == 'C') access(ed[u]), val[ed[u]] = v, update(ed[u]);
			else {
				if (ch[0] == 'N') get_path(u, v), reverse(v);
				else if (ch[0] == 'Q') get_path(u, v), printf("%d\n", max[v]);
			}
		}
	}
	return 0;
}
