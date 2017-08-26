#include <stdio.h>
#include <memory.h>
#define N 55
#define M 10
typedef long long ll;
ll n, m;
ll f[N];
int main() {
	scanf("%lld%lld", &n, &m);
	memset(f,0,sizeof(f));
	f[0] = f[1] = 1;
	for(int i = 2; i <= n + 1; i++) {
		if(i<=m) f[i]=f[i-1]*2;
		else f[i]=f[i-1]*2-f[i-m-1];
	}
	printf("%lld", f[n + 1]);
	return 0;
}