#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
typedef long long ll;
const int N = 505;
ll dis[N][N], ans[N], d[N];
bool vis[N];
int main() {
	int i, j, k, l, n;
	scanf("%d", &n);
	FOR(i,1,n) FOR(j,1,n) scanf("%I64d", &dis[i][j]), ans[0] += dis[i][j];
	FOR(i,1,n) scanf("%d", &d[i]);
	for(l=n;l;--l) {
		k = d[l]; vis[k] = 1;
		FOR(i,1,n) FOR(j,1,n) {
			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			if (vis[i] && vis[j]) ans[l] += dis[i][j];
		}
	}
	FOR(i,1,n) printf("%I64d ", ans[i]);
	return 0;
}