#include <cstdio>
#include <cstring>
#include <queue>
#define N 50005
using namespace std;

int head[N], next[N], to[N], key[N], cnt = 0;

queue<int> temp[N];
bool vis[N];

void bfs(int src) {
	int q[N];
	q.push(src);
	bool getkey[N];
	vis[src] = 1;
	memset(getkey, 0, sizeof(getkey));

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		//check for any nodes need this weapon
		getkey[u] = 1;
		while(!temp[u].empty()) {
			int v = temp[u].front();
			temp[u].pop();
			if(!vis[v]) {
				q.push(v);
				vis[v] = 1;
			}
		}

		for(int i = head[u]; i != -1; i = next[i]) {
			int v = to[i];
			int k = key[i];
			if(!getkey[k]) {
				temp[k].push(v);
				continue;
			}
			if(!vis[v]) {
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}

void add(int u, int v, int w) {
	next[cnt] = head[u];
	to[cnt] = v;
	key[cnt] = w;
	head[u] = cnt++;
}

int main() {
	int n, j, m, a, b, c;
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &n, &j, &m);
	while(m--) {
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
		add(b, a, c);
	}
	bfs(j);
	for(int i = 1; i <= n; i++)
		printf("%d:%s", i, (vis[i]?"Yes":"No"));

	return 0;
}