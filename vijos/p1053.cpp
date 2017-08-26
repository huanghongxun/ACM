#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define N 1005
#define M 100005

typedef long long ll;

struct node {
	int to;
	ll val;
	node(int a, ll b) {
		to=a,val=b;
	}
};

vector<node> edge[N];

int n, m, s, a, b;
ll c;

bool allvis[N];
bool vis[N];
int tot[N];
ll dis[N];
bool visEdge[M];

void dfs(int u)
{
	for(int i=0;i<)
}

bool spfa(int src)
{
	queue<int> q;
	q.push(src);
	for(int i=1;i<=n;i++)dis[i]=0x7fffffff;
	vis[src]=1;
	dis[src]=0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		tot[u]++;
		allvis[u]=1;
		if(tot[u]>n) return false;
		for(int i=0;i<edge[u].size();i++)
		{
			if(dis[edge[u][i].to]>dis[u]+edge[u][i].val) {
				dis[edge[u][i].to]=dis[u]+edge[u][i].val;
				if(!vis[edge[u][i].to])
				{
					vis[edge[u][i].to]=1;
					q.push(edge[u][i].to);
				}
			}
		}
		vis[u]=0;
	}
	return true;
}

int main()
{
	scanf("%d%d%d", &n, &m, &s);
	while(m--) {
		scanf("%d%d%lld", &a, &b, &c);
		edge[a].push_back(node(b,c));
	}
	memset(tot,0,sizeof(tot));
	memset(vis,0,sizeof(vis));
	memset(allvis,0,sizeof(allvis));
	if(spfa(s))
	{
		for(int i=1;i<=n;i++)
			if(!allvis[i])
				if(!spfa(i))
					goto noans;
		spfa(s);
		for(int i=1;i<=n;i++)
		{
			if(dis[i]==0x7fffffff)
				printf("NoPath\n");
			else
				printf("%lld\n", dis[i]);
		}
	}
	else
	{
noans:
		printf("-1\n");
	}

	return 0;
}