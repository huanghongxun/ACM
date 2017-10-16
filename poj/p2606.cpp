// POJ 2606, URAL 1052
#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
int x[728], y[728];
int main() {
    int n, i, j, k, ma = 2;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d%d", &x[i], &y[i]);
    FOR(i,1,n) FOR(j,i+1,n) {
        int ans = 2;
        FOR(k,j+1,n) {
            if ((x[j] - x[i]) * (y[k] - y[j]) == (y[j] - y[i]) * (x[k] - x[j]))
                ++ans;
            if (ans > ma)
                ma = ans;
        }
    }
    printf("%d", ma);
    return 0;
}