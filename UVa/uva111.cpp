#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;
int f[32], a[32], dp[32];
int main() {
    int n, i, j, k, ans;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", &k), f[i] = k;
    while (1) {
        FOR(i,1,n) 
            if (scanf("%d", &k) == EOF)
                return 0;
            else
                a[k] = f[i];
        memset(dp, 0, sizeof dp);
        dp[1] = 1; a[0] = 0; ans = 0;
        FOR(i,2,n) FOR(j,0,i-1)
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        FOR(i,1,n) ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }

    return 0;
}