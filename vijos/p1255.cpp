#include <cstdio>
#include <cstring>
long box[302][302];
long n, m, i, j, l, x, y;
long long value[302];
long long k, mm;
long long max(long long a, long long b) {
	return (a>b?a:b);
}
int main() {
	k = 0;
	scanf("%ld%ld", &n, &m);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++) {
			scanf("%ld", &box[i][j]);
			if(box[i][j] == 0)
				box[i][j] = -2147483648;
		}
	for(x = 1; x <= n; x++) {
		for(y = x; y <= n; y++) {
			for(i = 1; i <= m; i++)
				value[i] = value[i] + box[y][i];
			for(i = 1; i <= m; i++) {
				mm = max(mm + value[i], value[i]);
				if(mm > k)
					k = mm;
			}
			mm = 0;
		}
		memset(value, 0, sizeof(value));
	}
	printf("%lld", k);

	return 0;
}