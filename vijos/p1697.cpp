#include <cstdio>
#include <cstring>
#define N 205
#define FOR(i,n) for(i=1;i<=n;i++)
using namespace std;

int f[N][N];
int i, a, b, n, m, q;
char c;

bool floyd() {
	int k, i, j, t;
	FOR(k,n) FOR(i,n) FOR(j,n)
		if(i != j && f[i][k]!=0&&f[k][j]!=0) {
			t = f[i][j];
			f[i][j] = f[i][k] * f[k][j];
			if(-t==f[i][j]&&t!=0) return false;
		}
	return true;
}

int main() {
	scanf("%d%d%d\n", &n, &m, &q);
	memset(f, 0, sizeof(f));
	for(i = 0; i < m; i++) {
		scanf("l%d %c l%d\n", &a, &c, &b);
		if(f[a][b] != 0) {
			i = -1;
			break;
		}
		f[b][a] = f[a][b] = c == 'p' ? 1 : -1;
	}
	if(floyd() && i != -1) {
		long ans = 0;
		FOR(a,n) FOR(b,n) if(a!=b&&f[a][b]==1) {
			ans++;
		}
		printf("%ld\n",ans/2);
		while(q--) {
			scanf("l%d l%d\n", &a, &b);
			printf("%s\n", f[a][b] == 0 ? "No idea." : f[a][b] == 1 ? "Parallel." : "Vertical.");
		}
	} else {
		printf("There must be something wrong...");
	}

	return 0;
}