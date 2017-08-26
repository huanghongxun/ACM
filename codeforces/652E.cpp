#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define clr(i,j) memset(i,j,sizeof(i))
#define FOR(i,j,k) for(i=j;i<=k;++i)

const int N = 300005, M = 2 * N;

struct Graph {
	int h[N], p[M], fr[M], v[M], w[M], val[N], dis[N], vis[N], cnt, id, n;
	int dfn[N], low[N], instack[N], stack[N], belong[N], bcc, top;

	Graph() : cnt(0) {}

	void add(int a, int b, int c) {
		p[++cnt] = h[a]; fr[cnt] = a; v[cnt] = b; w[cnt] = c; h[a] = cnt;
		p[++cnt] = h[b]; fr[cnt] = b; v[cnt] = a; w[cnt] = c; h[b] = cnt;
	}

	void tarjan(int u, int fa) {
		int i;
		dfn[u] = low[u] = ++id;
		instack[u] = 1; stack[++top] = u;
		for (i = h[u]; i; i = p[i]) {
			if (v[i] == fa) continue;
			if (!dfn[v[i]]) {
				tarjan(v[i], u);
				low[u] = min(low[v[i]], low[u]);
			} else if (instack[v[i]])
				low[u] = min(dfn[v[i]], low[u]);
		}

		if (dfn[u] == low[u]) {
			++bcc;
			do {
				i = stack[top--];
				belong[i] = bcc;
				instack[i] = 0;
			} while (i != u);
		}
	}

	void do_bcc() {
		id = 0; top = 0; bcc = 0; int i;
		FOR(i,1,n) if (!dfn[i]) tarjan(i, 0);
	}

	void rebuild(Graph &out) {
		for (int i = 1; i <= cnt; i += 2)
			if (belong[fr[i]] != belong[v[i]])
				out.add(belong[fr[i]], belong[v[i]], w[i]);
			else if (w[i])
				out.val[belong[fr[i]]] = 1;
	}

	bool calc(int x, int y) {
		queue<int> q; q.push(x);
		dis[x] = val[x]; vis[x] = 1;
		while (!q.empty()) {
			int u = q.front(), i; q.pop();
			for (i = h[u]; i; i = p[i]) if (!vis[v[i]]) {
				if (dis[v[i]] < dis[u] + w[i] + val[v[i]])
					dis[v[i]] = dis[u] + w[i] + val[v[i]];
				q.push(v[i]); vis[v[i]] = 1;
			}
		}
		return dis[y];
	}
} base, ne;

int main() {
	int n, m, i, a, b, c;
	scanf("%d%d", &n, &m);
	base.n = n;
	FOR(i,1,m) {
		scanf("%d%d%d", &a, &b, &c);
		base.add(a, b, c);
	}
	scanf("%d%d", &a, &b);
	base.do_bcc(); base.rebuild(ne);
	puts(ne.calc(base.belong[a], base.belong[b]) ? "YES" : "NO");
	return 0;
}