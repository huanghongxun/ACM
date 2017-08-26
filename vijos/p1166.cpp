#include <cstdio>

int main() {
	long long ans = 1;
	int n, k, h, i, j, s;
	scanf("%d%d%d", &n, &k, &h);
	for(i=n-k+1;i<=n;i++) ans*=i;
	for(i=1;i<=h;i++) {
		scanf("%d", &s);
		for(j=2;j<=s;j++)
			ans/=j;
	}
	for(i=n-k+1;i<=n;i++) ans*=i;
	printf("%lld", ans);

	return 0;
}