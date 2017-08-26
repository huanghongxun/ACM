#include <cstdio>

int h[N], p[M], t[M], cnt = 0;

void add(int u, int v) {
	p[cnt] = h[u], t[cnt] = v, h[u] = cnt++;
}

void bfs() {
	int i, j, x;

	int f = 0, r = 0;
	q[r++] = 0;
	fa[0] = -1;
	while(f < r) {
		int x = q[f++];
		for(int i = h[x]; i != -1; i = p[i])
	}
}

int main() {
	return 0;
}