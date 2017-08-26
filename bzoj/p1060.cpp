#include <cstdio>
const int N = 500005, M = N * 2;
int h[N], p[M], v[M], w[M], cnt = 0;
long long ans = 0, dis[N];
inline void add(int a, int b, int c) {
	p[++cnt] = h[a]; v[cnt] = b; w[cnt] = c; h[a] = cnt;
}

void dfs(int x, int fa) {
	for (int i = h[x]; i; i = p[i]) if (v[i] != fa) {
		dfs(v[i], x);
		if (dis[x] < dis[v[i]] + w[i])
			dis[x] = dis[v[i]] + w[i];
	}
	for (int i = h[x]; i; i = p[i]) if (v[i] != fa) {
		ans += dis[x] - w[i] - dis[v[i]];
	}
}

int main() {
	int n, s, a, b, c;
	scanf("%d%d", &n, &s);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c); add(b, a, c);
	}
	dfs(s, 0);
	printf("%lld", ans);
	return 0;
}