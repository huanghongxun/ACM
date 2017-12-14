#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define foreach(it,v) for(vector<Edge>::iterator it=v.begin();it!=v.end();++it)
using namespace std;
#define M 310
using namespace std;

struct Edge {
	int u, v, w;
	bool operator< (const Edge &b) const {
		return w > b.w;
	}
};

vector<Edge> g[M];

void add(int a, int b, int c) {
	g[a].push_back((Edge) {a, b, c});
	g[b].push_back((Edge) {b, a, c});
}

int prim(int n) {
	static bool v[M];
	priority_queue<Edge> q;
	memset(v, 0, sizeof v);
	int res = 0;

	foreach (it, g[1])
		q.push(*it);
	v[1] = 1;
	while (!q.empty()) {
		Edge e = q.top(); q.pop();
		if (v[e.v]) continue;
		v[e.v] = 1;
		res += e.w;
		foreach (it, g[e.v]) {
			if (!v[it->v])
				q.push(*it);
		}
	}

	return res;
}
int main() {
	int n, m, x, y, z;
	while (scanf("%d", &n) != EOF && n) {
		scanf("%d", &m);
		for (int i = 1; i <= n; ++ i)
			g[i].clear();
		while (m --) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
		}
		printf("%d\n", prim(n));
	}
	return 0;
}
