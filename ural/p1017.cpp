#include <cstdio>
long long dp[512];

int main() {
    int n, i, j;
    scanf("%d", &n);
    dp[0] = 1;
    for (i = 1; i <= n; ++i)
        for (j = n; j >= i; --j)
            dp[j] += dp[j - i];

    printf("%lld\n", dp[n] - 1);

    return 0;
}