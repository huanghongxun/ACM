#include <iostream>
#include <vector>
using namespace std;
#define N 105

int n, k, m, s, t;

struct EDGE
{
	int v, d;
	EDGE(int v, int d) {
		this->v = v;
		this->d = d;
	}
};

vector<int> edge[N];

int main()
{
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	int u, v, d;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>d;
		edge[u].push_back(EDGE(v,d));
		edge[v].push_back(EDGE(u,d));
	}

	
	return 0;
}