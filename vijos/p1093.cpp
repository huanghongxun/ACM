#include <stdio.h>
#include <memory.h>
#define N 10001
#define MOD 7654321
int n;
int f[N][5];
int main() {
	scanf("%d", &n);
	memset(f, 0, sizeof(f));
	f[n][1] = f[n][2] = f[n][3] = f[n][4] = 1;
	for(int i = n - 1; i >= 1; i--) {
		f[i][1] = (f[i][1] + f[i + 1][2]) % MOD;
		f[i][4] = (f[i][4] + f[i + 1][3]) % MOD;
		f[i][2] = (f[i][2] + f[i + 1][1] + f[i + 1][3]) % MOD;
		f[i][3] = (f[i][3] + f[i + 1][2] + f[i + 1][4]) % MOD;
	}
	printf("%d", f[1][1]);
	return 0;
}