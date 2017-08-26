#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 200005, M = N * 2;
int h[N], p[M], v[M], cnt = 0, c[N], color[N];
void add(int a, int b) {
	p[++cnt] = h[a]; v[cnt] = b; h[a] = cnt;
}
void dfs(int x, int fa, int to) {
	for (int i = h[x]; i; i = p[i])
		if (v[i] != fa && color[v[i]] != to)
			color[v[i]] = to, dfs(v[i], x, to);
}
int main() {
	int n, i, a, b, ans1 = 0, ans2 = 0;
	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", c + i);
	FOR(i,2,n) {
		scanf("%d%d", &a, &b);
		add(a, b); add(b, a);
	}
	FOR(i,1,n) color[i] = c[i];
	FOR(i,1,n) if (color[i] == 0) color[i] = 1, dfs(i, 0, 1), ++ans1;
	FOR(i,1,n) color[i] = c[i];
	FOR(i,1,n) if (color[i] == 1) color[i] = 0, dfs(i, 0, 0), ++ans2;
	printf("%d", ans1 < ans2 ? ans1 : ans2);

	return 0;
}