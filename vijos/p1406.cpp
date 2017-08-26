#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
char a[22][22];
long f[22][22];
long x[10005], y[10005];
long n, m, h, t, i, j, nowx, nowy, xx, yy, ans;

int main() {
	cin>>n>>m;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
			cin>>a[i][j];
	}
	memset(f, 127, sizeof(f));
	for(i = 1; i <= m; i++) {
		x[i] = 1;
		y[i] = i;
		f[1][i] = 1;
	}
	h = 0; t = m;
	while(h < t) {
		h++;
		nowx = x[h]; nowy = y[h];
		for(i = 0; i < 4; i++) {
			xx = nowx + dx[i];
			yy = nowy + dy[i];
			if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if(a[xx][yy] == a[nowx][nowy] && f[xx][yy] > f[nowx][nowy]) {
				f[xx][yy] = f[nowx][nowy];
				t++;
				x[t] = xx; y[t] = yy;
			}
			if(a[xx][yy] != a[nowx][nowy] && f[xx][yy] > f[nowx][nowy] + 1) {
				f[xx][yy] = f[nowx][nowy] + 1;
				t++;
				x[t] = xx; y[t] = yy;
			}
		}
	}

	ans = 2147483647;
	for(i = 1; i <= m; i++)
		if(f[n][i] < ans)
			ans = f[n][i];
	cout<<ans;

	return 0;
}