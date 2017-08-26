#include <cstdio>
#include <cstring>
#define N 5005
#define M 10005
using namespace std;
int map[N][N], n, m, idx = 0, cnt;
int dfn[N], v[M], p[M], h[N] = {0}, b[N], x[N], y[N];
void add(int x,int y) {
	v[++cnt] = y; p[cnt] = h[x]; h[x] = cnt; map[x][y]++;
}
void dfs(int k) {
	dfn[k] = idx;
	for (int i = h[k]; i; i = p[i])
		if (dfn[v[i]] != idx && map[k][v[i]])
			dfs(v[i]);
}
int main() {
	memset(map, 0, sizeof map);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", x + i, y + i, b + i);
		add(x[i], y[i]);
		if (!b[i]) add(y[i], x[i]);
    }
	for (int i = 1; i <= m; i++)
		if (!b[i]) {
			idx++;
			map[x[i]][y[i]]--;
			dfs(x[i]);
			map[x[i]][y[i]]++;
			if (dfn[y[i]] != idx) map[y[i]][x[i]]--;
			else b[i] = 1, map[x[i]][y[i]]--;
	    } else b[i] = 0;
	for (int i = 1; i <= m; i++)
		printf("%d\n", b[i]);
	return 0;
}