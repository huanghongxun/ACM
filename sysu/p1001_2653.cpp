#include <cstdio>
const int mod = 1000000007;
int f[100005];
int main() {
	int i, n, sum = 0;
	scanf("%d", &n);
	f[0] = 0; f[1] = 1;
	for (i = 2; i <= n; ++ i) {
		f[i] = (f[i - 1] + f[i - 2]) % mod;
		sum = (sum + f[i]) % mod;
	}
	if (n >= 1) ++ sum;
	printf("%d\n", sum);
	return 0;
}