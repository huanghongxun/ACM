#include <stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
#define M 50
#define N 50


int n, m;
int i, j, k;
int p, q;
int width, height;
int hei[M][N];
char canvas[900][900];

void draw(int x, int y)
{
	int i, j;
	for(i = y + 1; i < y + 4; i++)
		canvas[x][i] = canvas[x - 3][i] = canvas[x - 5][i + 2] = '-';
	for(i = x - 1; i > x - 3; i--)
		canvas[i][y] = canvas[i][y + 4] = canvas[i - 2][y + 6] = '|';
	for(i = x - 1; i > x - 3; i--)
		for(j = y + 1; j < y + 4; j++)
			canvas[i][j] = ' ';
	for(i = x - 2; i > x - 4; i--)
		canvas[i][y + 5] = ' ';
	for(i = y + 2; i < y + 5; i++)
		canvas[x - 4][i] = ' ';
	canvas[x][y] = canvas[x - 3][y] = canvas[x][y + 4] = canvas[x - 3][y + 4] = '+';
	canvas[x - 4][y + 1] = canvas[x - 4][y + 5] = canvas[x - 1][y + 5] = '/';
	canvas[x - 5][y + 2] = canvas[x - 5][y + 6] = canvas[x - 2][y + 6] = '+';
}

int main()
{
	scanf("%d%d", &m, &n);
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &hei[i][j]);
	width = 4 * n + 1 + 2 * m;
	height = 0;
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			height = max(height, hei[i][j] * 3 + 1 + 2 * (m - i) + 2);
	for(i = 1; i <= height; i++)
		for(j = 1; j <= width; j++)
			canvas[i][j] = '.';
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
		{
			for(k = 1; k <= hei[i][j]; k++)
				draw(height - 2 * (m - i) - ((k-1)*3), 4 * (j - 1) + 1 + (m - i) * 2);
		}
	for(p = 1; p <= height; p++)
	{
				for(q = 1; q <= width; q++)
			putchar(canvas[p][q]);
		putchar('\n');
	}
	return 0;
}