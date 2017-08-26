#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 10005
#define M 50005
#define Q 30005
struct E
{
	int x, y, z;
} edge[M];

bool operator < (const E &a, const E &b) {
	return a.z > b.z;
}

int head[N], head_ask[N], dis[N], to[4*M], next[4*M], wei[4*M], cnt = 0;
int ans[Q], f[N], vis[N], anc[N];
int n, m, q, i;

void add(int u, int v, int w) {
	next[cnt] = head[u];
	to[cnt] = v;
	wei[cnt] = w;
	head[u] = cnt++;
}

void add_ask(int u, int v, int w) {
	next[cnt] = head_ask[u];
	to[cnt] = v;
	wei[cnt] = w;
	head_ask[u] = cnt++;
}

int find(int x)
{
	return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	f[fx] = fy;
}

void kruskal()
{
	sort(edge, edge + m);
	for(int i = 0; i < m; i++) {
		if(find(edge[i].x) != find(edge[i].y))
		{
			merge(edge[i].x, edge[i].y);
			cout<<"ADD:"<<edge[i].x<<' '<<edge[i].y<<' '<<edge[i].z<<endl;
			add(edge[i].x, edge[i].y, edge[i].z);
			add(edge[i].y, edge[i].x, edge[i].z);
		}
	}
}

void tarjan(int u, int w)
{
	cout<<"tarjan:"<<u<<' '<<w<<endl;
	int v;
	dis[u] = w;
	anc[u] = u;
	vis[u] = 1;
	for(int i = head[u]; i != -1; i = next[i])
	{
		v = to[i];
		if(!vis[v])
		{
			tarjan(v, wei[i] + w);
			merge(v, u);
			anc[find(u)] = u;
		}
	}
	for(int i = head_ask[u]; i != -1; i = next[i])
	{
		v = to[i];
		cout<<"CHECK:"<<u<<' '<<v<<endl;
		if(vis[v])
		{
			cout<<"LCA:"<<anc[find(v)]<<endl;
			ans[wei[i]] = min(dis[u], dis[v]);// - 2 * dis[find(v)];
			cout<<"ans["<<wei[i]<<"] = "<<ans[wei[i]]<<endl;
		}
	}
}

int main()
{
	cin>>n>>m;
	for(i = 1; i <= n; i++) {
		f[i] = i;
		vis[i] = 0;
		head[i] = head_ask[i] = -1;
	}
	for(i = 0; i < m; i++) {
		cin>>edge[i].x>>edge[i].y>>edge[i].z;
	}
	kruskal();
	for(i = 1; i <= n; i++) {
		f[i] = i;
	}
	cin>>q;
	int a, b;
	for(i = 0; i < q; i++) {
		cin>>a>>b;
		add_ask(a, b, i);
		add_ask(b, a, i);
	}
	memset(ans, -1, sizeof(ans));
	tarjan(1, 0);
	for(i = 0; i < q; i++) {
		cout<<ans[i]<<endl;
	}

	return 0;
}