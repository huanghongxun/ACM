#include <cstdio>
#define rep(i,j,k) for(i=j;i<k;++i)
const int value[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
long long f[32768];

int main() {
    double a;
    int i, j;
    f[0] = 1;
    rep(i,0,11) rep(j,value[i], 32768)
        f[j] += f[j - value[i]];
    while (scanf("%lf", &a) && a != 0)
    	printf("%6.2lf%17lld\n", a, f[(int)(a * 100 + 0.5)]);

    return 0;
}