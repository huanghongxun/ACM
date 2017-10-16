#include <cstdio>
#define rep(i,j,k) for(i=j;i<k;++i)
int main() {
    char type[6][5] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };
    long long n[3][3], tot[6];

    while (scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",
        &n[0][0], &n[0][1], &n[0][2],
        &n[1][0], &n[1][1], &n[1][2],
        &n[2][0], &n[2][1], &n[2][2]) == 9) {
        tot[0] = n[1][0] + n[2][0] + n[0][2] + n[2][2] + n[0][1] + n[1][1];
        tot[1] = n[1][0] + n[2][0] + n[0][1] + n[2][1] + n[0][2] + n[1][2];
        tot[2] = n[1][2] + n[2][2] + n[0][0] + n[2][0] + n[0][1] + n[1][1];
        tot[3] = n[1][2] + n[2][2] + n[0][1] + n[2][1] + n[0][0] + n[1][0];
        tot[4] = n[1][1] + n[2][1] + n[0][0] + n[2][0] + n[0][2] + n[1][2];
        tot[5] = n[1][1] + n[2][1] + n[0][2] + n[2][2] + n[0][0] + n[1][0];
        long long i, mi = tot[0], p = 0;
        rep(i,0,6) if (tot[i] < mi) {
            mi = tot[i];
            p = i;
        }
        printf("%s %lld\n", type[p], tot[p]);
    }
    return 0;
}