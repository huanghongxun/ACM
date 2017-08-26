#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100005
typedef long long ll;
const int mod = 51061;
int read() {
	int s = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; '0' <= ch && ch <= '9'; ch = getchar()) s = s * 10 + ch - '0';
	return s * f;
}
int sz[N], l[N], r[N], fa[N], rev[N], sk[N];
ll sum[N], val[N], add[N], mul[N];

void update(int x) {
	sum[x] = (sum[l[x]] + sum[r[x]] + val[x]) % mod;
	sz[x] = (sz[l[x]] + sz[r[x]] + 1) % mod;
}

void modify(int x, int m, int a) {
	if (!x) return;
	val[x] = (val[x] * m + a) % mod;
	sum[x] = (sum[x] * m + a * sz[x]) % mod;
	add[x] = (add[x] * m + a) % mod;
	mul[x] = (mul[x] * m) % mod;
}

void pushdown(int x) {
	if (rev[x])
		rev[x] ^= 1, rev[l[x]] ^= 1, rev[r[x]] ^= 1, std::swap(l[x], r[x]);
	if(mul[x] != 1 || add[x] != 0) modify(l[x], mul[x], add[x]), modify(r[x], mul[x], add[x]);
	mul[x] = 1; add[x] = 0;
}

bool isRoot(int x) { return l[fa[x]] != x && r[fa[x]] != x; }

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

void access(int x) { for(int t = 0; x; t = x, x = fa[x]) splay(x), r[x] = t, update(x); }
void makeroot(int x) { access(x); splay(x); rev[x] ^= 1; }
void get_path(int x, int y) { makeroot(x); access(y); splay(y); }
void link(int x, int y) { makeroot(x); fa[x] = y; } 
void cut(int x, int y) { makeroot(x); access(y); splay(y); l[y] = fa[x] = 0; }

int main() {
	int n = read(), m = read(), i, x, y; char ch[2];
	for (i = 1; i <= n; i++) fa[i] = 0, sz[i] = mul[i] = val[i] = sum[i] = 1;
	for (i = 1; i < n; i++) link(read(), read());
	while(m--) {
		scanf("%s", ch); x = read(), y = read(); 
		switch(ch[0]) {
		case '+':
			get_path(x, y); modify(y, 1, read());
			break;
		case '-':
			cut(x, y); x = read(), y = read(); link(x, y);
			break;
		case '*':
			get_path(x, y); modify(y, read(), 0);
			break;
		case '/':
			get_path(x, y); printf("%lld\n", sum[y]);
			break;
		}
	}
	return 0;
}
