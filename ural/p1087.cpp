#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
int f[16384], k[64];
int main(){
    int i, j, m, n;
    scanf("%d%d", &n, &m);

    FOR(i,1,m) scanf("%d", &k[i]);
    FOR(i,2,n) FOR(j,1,m)
        if (i > k[j] && !f[i - k[j]]) {
            f[i] = 1;
            break;
        }
    printf("%d\n", f[n] ? 1 : 2);
    return 0;
}