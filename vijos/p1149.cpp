#include <cstdio>
int oil[], f[];
int dis[], totdis;

int i, j;

float getPrice(int from, int to) {
	return (dis[to] - dis[from]) * price[to] / run;
}

int main() {
	scanf("%d", &totdis);
	memset(f, 127, sizeof(f));
	scanf("%f%f%f%d", &maxcap, &run, &f[0], &n);
	for(i = 1; i <= n; i++)
		scanf("%d%f", &dis[i], &price[i]);
	for(i = 1; i <= n; i++)
		for(j = 0; j < i; j++) {
			f[i] = min(f[j] + 20 + getPrice(i, j), f[i]);
		}
	int mi = 0x7fffffff;
	for(j = 0; i <= n; j++)
		mi = min(f[j], mi);
	printf("%d", mi);
	return 0;
}