#include <cstdio>
#include <queue>
#include <cstring>
#define N 105
#define M 10005
using namespace std;

int p[N], l[N], x[N];
int m, n;
int dist[N]; bool vis[N];
int pre[N];
int head[N], next[M], to[M], wei[M], cnt = 0;
void spfa(int src) {
	queue<int> q;
	q.push(src);
	memset(vis, 0, sizeof(vis));
	memset(dist, 63, sizeof(dist));
	vis[src] = 1;
	dist[src] = 0;
	pre[src] = -1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i != -1; i = next[i]) {
			int v = to[i];
			if(dist[v] > dist[u] + wei[i] && l[v] <= l[u]) {
				for(int j = u; j != -1; j = pre[j])
					if(l[j] - l[v] > m) {
						v = -1;
						break;
					}
				if(v == -1) continue;
				dist[v] = dist[u] + wei[i];
				pre[v] = u;
				if(!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = 0;
	}
}
void add(int u, int v, int w) {
	next[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

int main() {
	scanf("%d%d", &m, &n);
	memset(head, -1, sizeof(head));
	int i, a, b, x;
	for(i = 1; i <= n; i++) {
		scanf("%d%d%d", &p[i], &l[i], &x);
		while(x--) {
			scanf("%d%d", &a, &b);
			add(i, a, b);
		}
	}
	spfa(1);
	int mi = 0x7ffffff;
	for(i = 1; i <= n; i++) {
		if(dist[i] + p[i] < mi)
			mi = dist[i] + p[i];
	}
	printf("%d", mi);
	return 0;
}