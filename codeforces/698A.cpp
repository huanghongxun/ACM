#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 105;
int a[N], dp[N][3];

int main() {
    int n, i;
    scanf("%d", &n);
    FOR(i,1,n) scanf("%d", a + i);
    memset(dp, 0x7f, sizeof dp);
    dp[0][0] = 0;
    FOR(i,1,n) {
        dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + 1;
        if (a[i] == 2 || a[i] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]); // gym
        if (a[i] == 1 || a[i] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]); // contest
    }
    printf("%d", min(min(dp[n][0], dp[n][1]), dp[n][2]));
    return 0;
}