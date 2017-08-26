#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#define N 1005
#define M 10005
using namespace std;

int n, m;
int vis[N], dfn[N], low[N], ti = 0;
int head[N], next[M], to[M], cnt = 0;
vector<int> in[N], out[N];
stack<int> stk;
int scc[N], scc_count;
int scc_e[N][N];

void tarjan(int u) {
	stk.push(u);
	vis[u] = true;
	low[u] = dfn[u] = ++ti;
	int i;
	for(i = head[u]; i != -1; i = next[i]) {
		int v = to[i];
		if(dfn[u] == 0) {
			tarjan(u);
			low[u] = min(low[u], low[v]);
		} else if(vis[u]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u]) {
		scc_count++;
		do {
			i = stk.top();
			stk.pop();
			vis[i] = false;
			scc[i] = scc_count;
		} while(i != u);
	}
}

void floyd() {
	for(int k = 1; k <= scc_count; k++)
		for(int i = 1; i <= scc_count; i++)
			for(int j = 1; j <= scc_count; j++) {
				scc_e[i][j] |= scc_e[i][k] && scc_e[k][j];
			}
}

void add(int u, int v) {
	next[cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt++;
}

int main() {
	cin>>n>>m;
	int a, b;
	while(m--) {
		cin>>a>>b;
		add(a, b);
	}
	memset(head, -1, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(vis, 0, sizeof(vis));
	for(a = 1; a <= n; a++)
		if(dfn[a] == 0)
			tarjan(a);
	cout<<scc_count<<endl;
	for(a = 1; a <= n; a++) {
		for(b = head[a]; b != -1; b = next[b])
			if(scc[a] != scc[to[b]]) {
				in[to[b]].push_back(a);
				out[a].push_back(to[b]);
				scc_e[a][to[b]] = 1;
			}
	}
	for(a = 1; a <= scc_count; a++) {
		bool flag = false;
		for(vector<int>::iterator i = in[a].begin();
			i != in[a].end(); i++) {
			flag = true;
			cout<<*i<<' ';
		}
		if(!flag) cout<<-1;

		cout<<endl;
	}

	return 0;
}