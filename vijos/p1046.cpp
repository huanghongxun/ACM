#include<stdio.h>
#include <iostream>
using namespace std;
const long MAX = 1000000;
long n, m, x, y, d, i, j, k;
long dist[111][111],map[111][111],ans;
long min(long a,long b)
{
	if(a < b) return a;
	else return b;
}
int main()
{
	while(scanf("%ld%ld",&n,&m)!=EOF)
	{
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				map[i][j] = MAX;
		for(i = 1; i <= m; i++)
		{
			cin>>x>>y>>d;
			map[x][y] = d;
			map[y][x] = d;
		}
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				dist[i][j] = map[i][j];
		ans = MAX;
		for(k = 1; k <= n; k++)
		{
			for(i = 1; i < k; i++)
				for(j = i + 1; j < k; j++)
					ans = min(dist[i][j] + map[i][k] + map[k][j], ans);
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
		}
		if(ans == MAX)
		cout << "No solution." << endl;
		else cout << ans << endl;
	}
	return 0;
}