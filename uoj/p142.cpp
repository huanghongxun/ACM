#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define rep(i,j,k) for(i=j;i<k;i++)
#define FORD(i,j,k) for(i=j;i>=k;i--)
using namespace std;
typedef long long ll;
ll read() {
	ll s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
#define N 100005
#define M N*4
map<ll, ll> grid;
ll head[N], to[M], next[M], vis[N], q[N], cnt, n, m, k;
struct {
	ll x, y;
	bool onEdge;
} point[N];

inline ll p(ll x, ll y) { return x * m + y; }

ll getId(ll x, ll y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return -1;
	if(grid.count(p(x, y))) return grid[p(x,y)];
	else return -1;
}

void add(ll u, ll v) {
	if (u == -1 || v == -1) return;
	to[++cnt] = v; next[cnt] = head[u]; head[u] = cnt;
	to[++cnt] = u; next[cnt] = head[v]; head[v] = cnt;
}

bool bfs(ll i) {
	int f = 0, r = 0, top = 0, bottom = 0, mintop = 2147483647, maxtop = -1, minbottom = 2147483647, maxbottom = -1;
	bool left = 0, right = 0;
	q[r++] = i;
	while(f < r) {
		int u = q[f++];
		if (point[u].x == 0) mintop = min(mintop, point[u].y), maxtop = max(maxtop, point[u].y);
		if (point[u].x == n - 1) minbottom = min(minbottom, point[u].y), maxbottom = max(maxbottom, point[u].y);
		if (point[u].y == 0) left = 1;
		if (point[u].y == m - 1) right = 1;
		for (int i = head[u]; i; i = next[i])
			if (!vis[to[i]]) {
				q[r++] = to[i]; vis[to[i]] = 1;
			}
	}
	if (maxtop - mintop + 1 != top || maxbottom - minbottom != bottom) return true;
	return left == 1 && right == 1;
}

int main() {
	ll t = read(), i, x, y;
	while (t--) {
		grid.clear(); cnt = 0;
		memset(head, 0, sizeof head);
		memset(vis, 0, sizeof vis);
		n = read(); m = read(); k = read();
		rep(i,0,k) {
			x = read() - 1, y = read() - 1;
			grid[p(x, y)] = i;
			if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
				point[i].onEdge = 1;
			point[i].x = x; point[i].y = y;
			add(i, getId(x, y - 1));
			add(i, getId(x, y + 1));
			add(i, getId(x - 1, y));
			add(i, getId(x + 1, y));
			add(i, getId(x - 1, y - 1));
			add(i, getId(x + 1, y - 1));
			add(i, getId(x - 1, y + 1));
			add(i, getId(x + 1, y + 1));
		}
		int flag = 0;
		rep(i,0,k) {
			if (!vis[i])
				if(bfs(i)) {
					flag = 1;
					break;
				}
		}
		if(flag)printf("No\n");else printf("Yes\n");
	}
	
	return 0;
}
