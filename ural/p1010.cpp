#include <cstdio>
#include <cstdlib>
#include <cmath>
#define FOR(i,j,k) for(i=j;i<=k;++i)
typedef long long ll;
ll f[100005];

int main() {
    long long ma = -1;
    int n, i, p;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%lld", f + i);
    FOR(i,2,n)
        if (ma < llabs(f[i] - f[i - 1])) {
            ma = llabs(f[i] - f[i - 1]);
            p = i;
        }
    printf("%d %d\n", p - 1, p);

    return 0;
}