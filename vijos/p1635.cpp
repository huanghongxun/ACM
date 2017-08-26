#include <iostream>
#include <queue>
#include <cstring>
#define N 2005
using namespace std;

struct Edge
{
	int to, rp;
	Edge(){}
	Edge(int t, int r) {
		to = t;
		rp = r;
	}
};

Edge graph[N][N];
int graphs[N];

int main()
{
	int a, b, r, n;
	cin.sync_with_stdio(false);
	cin>>n;

	memset(graphs, 0, sizeof(graphs));
	
	for(a = 1; a <= n; a++)
		for(b = 1; b <= n; b++)
		{
			cin>>r;
			if(r != 0)
				graph[a][graphs[a]++] = Edge(b, r);
		}

	int dist[N];
	bool vis[N];
	int pre[N];
	memset(pre, -1, sizeof(pre));
	memset(dist, 127, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	vis[1] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < graphs[u]; i++)
		{
			if(dist[graph[u][i].to] > dist[u] + graph[u][i].rp)
			{
				dist[graph[u][i].to] = dist[u] + graph[u][i].rp;
				pre[graph[u][i].to] = u;
				if(!vis[graph[u][i].to])
				{
					vis[graph[u][i].to] = 1;
					q.push(graph[u][i].to);
				}
			}
		}
	}
	
	for(r = n, a = 0; r != -1; r = pre[r], a++)
		graphs[a] = r;
	for(r = a - 1; r >= 0; r--)
		cout<<graph[r]<<' ';
	cout<<endl<<dist[n];
	return 0;
}