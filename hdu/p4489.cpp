// UVALive 6177, HDU 4489
#include <cstdio>
const int N = 21;
long long dp[N][N], ans[N];

int main() {
    int T, kase, n, i, j;
    dp[1][1] = 1;
    ans[1] = 1;
    for (i = 2; i <= 20; ++i) {
        for (j = 2; j <= i; ++j) {
            dp[i][j] = dp[i - 1][i - j + 1] + dp[i][j - 1];
            ans[i] += dp[i][j];
        }
        ans[i] *= 2;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &kase, &n);
        printf("%d %lld\n", kase, ans[n]);
    }
    return 0;
}
