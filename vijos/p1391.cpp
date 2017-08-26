#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define N 2005
using namespace std;

struct Edge
{
	int to, rp;
	Edge(int t, int r) {
		to = t;
		rp = r;
	}
};

typedef vector<Edge>::iterator iter;

vector<Edge> graph[N];

int main()
{
	int a, b, r, n;
	cin.sync_with_stdio(false);
	cin>>n;
	while(cin>>a>>b>>r && a != 0 && b != 0 && r != 0) {
		graph[a].push_back(Edge(b, r));
	}

	int dist[N];
	memset(dist, 0, sizeof(dist));
	queue<int> q;
	q.push(1);
	dist[1] = 0x7ffffff;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(iter i = graph[u].begin();
			i != graph[u].end(); i++)
		{
			if(dist[i->to] < min(i->rp, dist[u]))
			{
				dist[i->to] = min(i->rp, dist[u]);
				q.push(i->to);
			}
		}
	}
	
	for(int i = 2; i <= n; i++)
		cout<<dist[i]<<endl;
	return 0;
}