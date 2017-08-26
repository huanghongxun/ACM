#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int read() {
	int ans = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while('0' <= ch && ch <= '9') { ans = ans * 10 + ch - '0'; ch = getchar(); }
	return ans * f;
}
const int N = 400005;
int n, cnt = 0;
int id = 0, pos[N], end[N];
int top[N] = {0}, size[N], fa[N], son[N] = {0};
int tag[N] = {0}, install[N] = {0}, dep[N];
int to[N], next[N], head[N] = {0};
void insert(int u,int v) {
	to[cnt] = v; next[cnt] = head[u]; head[u] = cnt++;
}
void dfs(int x, int depth) {
	size[x] = 1; dep[x] = depth; int k = 0;
	for(int i = head[x]; i != -1; i = next[i]) {
		dfs(to[i], depth + 1);
		size[x] += size[to[i]];
		if (size[to[i]] > k) k = size[to[i]], son[x] = to[i];
	}
}
void dfs2(int x, int anc) {
	top[x] = anc; pos[x] = ++id;
	if (son[x]) dfs2(son[x], anc);
	for(int i = head[x]; i != -1; i = next[i])
		if(to[i] != son[x])
			dfs2(to[i], to[i]);
	end[x] = id;
}

void pushdown(int l, int r, int k) {
	int mid = (l + r) / 2, lc = k * 2, rc = k * 2 + 1;
	tag[lc] = tag[rc] = tag[k];
	if (tag[k] == 1) install[lc] = mid - l + 1, install[rc] = r - mid;
	if (tag[k] == -1) install[lc] = install[rc] = 0;
	tag[k] = 0;
}

void add(int k, int l, int r, int x, int y, int val) {
	if (tag[k] && l != r) pushdown(l, r, k);
	if (l == x && y == r) {
		tag[k] = val;
		if(val == 1) install[k] = r - l + 1;
		if(val == -1) install[k] = 0;
		return;
	}
	int mid = (l + r) / 2;
	if (y <= mid) add(k * 2, l, mid, x, y, val);
	else if (x > mid) add(k * 2 + 1, mid + 1, r, x, y, val);
	else add(k * 2, l, mid, x, mid, val), add(k * 2 + 1, mid + 1, r, mid + 1, y, val);
	install[k] = install[k * 2] + install[k * 2 + 1];
}

void add(int x) {
	while(x) {
		add(1, 1, n, pos[top[x]], pos[x], 1);
		x = fa[top[x]];
	}
}

int query(int k, int l, int r, int x, int y) {
	if (tag[k] && l != r) pushdown(l, r, k);
	if (l == x && y == r) {
		return install[k];
	}
	int mid = (l + r) / 2;
	if (y <= mid) return query(k * 2, l, mid, x, y);
	else if (x > mid) return query(k * 2 + 1, mid + 1, r, x, y);
	else return query(k * 2, l, mid, x, mid) + query(k * 2 + 1, mid + 1, r, mid + 1, y);
}

int query(int x) {
	int ans = 0;
	while(x) {
		ans += query(1, 1, n, pos[top[x]], pos[x]);
		x = fa[top[x]];
	}
	return ans;
}

int main() {
	freopen("manager.in","r",stdin);
	freopen("manager.out","w",stdout);
	
	memset(head, -1, sizeof head);
	n = read();
	for(int i = 2; i <= n; i++) insert(fa[i] = read() + 1, i);
	dfs(1, 1); dfs2(1, 1);
	int m = read(), x;
	char ch[20];
	while(m--) {
		scanf("%s", ch);
		x = read() + 1;
		if (ch[0] == 'i') {
			if (query(1, 1, n, pos[x], pos[x]) == 1) printf("0\n");
			else {
				printf("%d\n", dep[x] - query(x)); add(x);
			}
		} else if(ch[0] == 'u') {
			if (query(1, 1, n, pos[x], pos[x]) == 0) printf("0\n");
			else {
				printf("%d\n", query(1, 1, n, pos[x], end[x]));
				add(1, 1, n, pos[x], end[x], -1);
			}
		}
	}
	return 0;
}
