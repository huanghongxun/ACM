#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 1000000
#define M 1000000

int head[N], next[M], to[M], wei[M], cnt = 0;

int add(int u, int v, int w) {
	next[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

int dist[N];
bool vis[N];

void spfa(int src) {
	queue<int> q;
	q.push(src);
	memset(vis, 0, sizeof vis);
	memset(dist, 127, sizeof dist);
	vis[src] = true;
	dist[src] = 0;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i != -1; i = next[i]) {
			int v = to[i];
			if(dist[v] > dist[u] + wei[i]) {
				dist[v] = dist[u] + wei[i];
				if(!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = false;
	}
}

int main() {
	int n, s, e, x, y, z;
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &s, &e);
	for(int i = s; i <= e + 1; i++)
		add(i, i - 1, 0);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y + 1, z);
	}
	spfa(s);
	printf("%d", dist[e+1]);

	return 0;
}