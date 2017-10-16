#include <cstdio>

long long dp[10000];
int main() {
    int n, k, i;
    scanf("%d%d", &n, &k);
    dp[0] = 1;
    dp[1] = k - 1;
    for (i = 2; i <= n; ++i)
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    printf("%lld\n", dp[n]);

    return 0;
}