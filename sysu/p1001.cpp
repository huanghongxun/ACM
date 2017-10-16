#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 10005;
char digits[N];
long long dp[N];
int main() {
    int i, len;
    while (scanf("%s", digits + 1) == 1) {
        len = strlen(digits + 1);
        if (len == 1 && digits[1] == '0') break;

        FOR(i,1,len) digits[i] -= '0';

        dp[0] = dp[1] = 1;
        FOR(i,2,len) {
            if (digits[i] == 0) dp[i] = 0;
            else dp[i] = dp[i - 1];
            if (digits[i - 1] == 2 && digits[i] > 6) continue;
            if (digits[i - 1] > 2 || digits[i - 1] == 0) continue; // 01 is not A.
            dp[i] += dp[i - 2];
        }
        printf("%lld\n", dp[len]);
    }
    return 0;
}