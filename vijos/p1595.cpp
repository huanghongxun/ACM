#include <iostream>
#include <stack>
#include <cstring>
#define N 105
#define M 10005
using namespace std;

int head[N], next[M], to[M], cnt = 0;
int indegree[N], outdegree[N];
int scc[N], scc_count = 0;
int dfn[N], low[N], ti = 0;
bool vis[N];
int n, i, j;
stack<int> stk;

void add(int u, int v) {
	next[cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt++;
}

void tarjan(int u) {
	low[u] = dfn[u] = ++ti;
	stk.push(u);
	int v;
	vis[u] = 1;
	for(int i = head[u]; i != -1; i = next[i]) {
		v = to[i];
		if(dfn[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(vis[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(low[u] == dfn[u]) {
		scc_count++;
		do {
			v = stk.top();
			stk.pop();
			scc[v] = scc_count;
		} while(u != v);
	}
}

int main() {
	cin>>n;
	memset(head, -1, sizeof(head));
	for(i = 1; i <= n; i++) {
		while(cin>>j && j != 0)
			add(i, j);
	}

	memset(dfn, 0, sizeof(dfn));
	memset(vis, 0, sizeof(vis));
	memset(indegree, 0, sizeof(indegree));
	memset(outdegree, 0, sizeof(outdegree));
	for(i = 1; i <= n; i++) {
		if(dfn[i] == 0)
			tarjan(i);
	}

	for(i = 1; i <= n; i++) {
		for(j = head[i]; j != -1; j = next[j]) {
			if(scc[i] != scc[to[j]]) {
				indegree[scc[to[j]]]++;
				outdegree[scc[i]]++;
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	for(i = 1; i <= scc_count; i++) {
		if(indegree[i] == 0) ans1++;
		if(outdegree[i] == 0) ans2++;
	}
	ans2 = max(ans1, ans2);
	if(scc_count == 1) { ans1 = 1; ans2 = 0; }
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}