#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;++i)

long long dp[64][32];

int main() {
    int i, j, n;
    while (scanf("%d", &n), n) {
        memset(dp, 0, sizeof dp);
        dp[0][n] = 1;
        FOR(i,1,2*n) FOR(j,0,n) { // i - days, j - whole pills
            int half = 2 * n - i - 2 * j;
            if (half < 0) break;
            if (half >= 0)
                dp[i][j] += dp[i - 1][j];
            if (j < n)
                dp[i][j] += dp[i - 1][j + 1];
        }
        printf("%lld\n", dp[2 * n][0]);
    }

    return 0;
}