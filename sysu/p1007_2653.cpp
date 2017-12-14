#include <cstdio>
const int N = 30005, M = 200005;
int p[M], h[N], v[M], vis[N], edge = 0, cnt = 0;

inline void add(int a, int b) {
	p[++edge] = h[a]; v[edge] = b; h[a] = edge;
	p[++edge] = h[b]; v[edge] = a; h[b] = edge;
}

void dfs(int t) {
	if (vis[t]) return;
	vis[t] = 1;
	++cnt;

	for (int i = h[t]; i; i = p[i])
		dfs(v[i]);
}

void removeNode(int t) {
	for (int i = h[t]; i; i = p[i])
		vis[v[i]] = 1;
}

int main() {
	int n, m, k, a, b;

	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		scanf("%d%d", &a, &b);
		add(a, b);
	}

	while (k--) {
		scanf("%d", &a);
		removeNode(a);
	}

	cnt = 0;
	dfs(1);
	printf("%d", n - cnt);
	return 0;
}