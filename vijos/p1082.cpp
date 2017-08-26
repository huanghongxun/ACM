#include <cstdio>
#include <queue>
#include <cstring>
#define N 5005
#define M 40005
#define INF 0x7ffffff
using namespace std;
int dist[N], vis[N], power[N], n, m, s, t, k;
int head[N], next[M], to[M], wei[M], len[M], cnt = 0;
int spfa(int src, int goal) {
	queue<int> q;
	q.push(src);
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
		dist[i] = INF;
	vis[src] = 1;
	dist[src] = 0;
	power[src] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i != -1; i = next[i]) {
			int v = to[i];
			if(v == 0) continue;
			if(dist[v] > dist[u] + len[i] && power[u] + wei[i] <= k) {
				dist[v] = dist[u] + len[i];
				power[v] = power[u] + wei[i];
				if(!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
		vis[u] = 0;
	}
	return dist[goal];
}
void add(int u, int v, int c, int w) {
	next[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = c;
	len[cnt] = w;
	head[u] = cnt++;
}
int main()
{
	int i;
	scanf("%d%d", &n, &m);
	int x, y, c, d;
	memset(head, -1, sizeof(head));
	for(i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &x, &y, &c, &d);
		add(x, y, c, d);
		add(y, x, c, d);
	}
	scanf("%d%d%d", &s, &t, &k);
	int dis = spfa(s, t);
	if(dis == INF)
		printf("-1");
	else
		printf("%d", dis);
	return 0;
}