#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int f[105][2005], c[105];
int main()
{
	scanf("%d", &n);
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
		sum += c[i];
	}
	memset(f, -1, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= sum; j++)
		{
			if(f[i - 1][j] != -1) f[i][j] = f[i - 1][j];
			if(j + c[i] <= sum && f[i - 1][j + c[i]] != -1)
			f[i][j] = max(f[i][j], f[i - 1][j + c[i]] + c[i]);
			if(j >= c[i] && f[i - 1][j - c[i]] != -1)
			f[i][j] = max(f[i][j], f[i - 1][j - c[i]]);
			if(c[i] > j && f[i - 1][c[i] - j] != -1)
			f[i][j] = max(f[i][j], f[i - 1][c[i] - j] + c[i] - j);
		}
	}
	if(f[n][0] > 0) printf("%d\n", f[n][0]);
	else printf("Impossible\n");
	return 0;
}