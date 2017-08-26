#include <cstdio>
#define N 100005
#define INF 0x7ffffff

int n, i, j, mi, beg, zero;
int h[N];
int ans = 0;

int main()
{
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &h[i]);
	ans = h[0];
	for(i = 0; i < n; i++)
		if(h[i + 1] > h[i])
			ans += h[i + 1] - h[i];
	/*while(1) {
		mi = INF;
		beg = 0;
		zero = 0;
		for(i = 0; i <= n; i++) {
			if(h[i] <= 0)
			{
				zero++;
				if(mi == INF) continue;
				for(j = beg; j < i; j++)
					h[j] -= mi;
				//printf("%d %d %d\n", beg + 1, i, mi);
				beg = i + 1;
				ans += mi;
				mi = INF;
			} else
			if(h[i] < mi) mi = h[i];
		}
		if(zero == n)
			break;
	}*/
	printf("%d", ans);

	return 0;
}