#include <stdio.h>
int main()
{
	int M, N, K, u[20][20], p[4000], ans1=0, ans2=0;
	int i, j, y, t, a, b, c = 0;
	scanf("%d%d%d", &M, &N, &K);
	y = 0;
	for(i = 0; i < M; i++)
	for(j = 0; j < N; j++)
	{
		scanf("%d", &u[i][j]);
		if(u[i][j] != 0)
		{
			p[y] = u[i][j];
			y++;
			if(u[i][j]>c)
			{
				a = i;
				b = j;
				c = u[i][j];
			}
		}
	}
	for(i = 0; i < y; i++)
		for(j = i + 1; j < y; j++)
			if(p[j] > p[i])
			{
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
	if(2 * (a + 2) <= K)
	{
		ans1 += u[a][b];
		ans2 = ans1;
		K -= a + 2;
		for(i=1;i<y;i++)
		{
			for(j = 0; j < M; j++)
			for(t = 0; t < N; t++)
			if(u[j][t] == p[i])
			{
				if(j >= a)
					K -= j - a;
				else
					K -= a - j;
				if(t >= b)
					K -= t - b;
				else
					K -= b - t;
				K--;
				ans1 += u[j][t];
				a = j;
				b = t;
			}
			if(a + 1 <= K)
				ans2 = ans1;
			else
				break;
		}
	}
	printf("%d", ans2);
	return 0;
}