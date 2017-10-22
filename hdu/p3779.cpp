// HDU 3779, UVaLive
#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 1024;
int dp[N][N], a[N], b[N], c[2 * N];
int main() {
    int i, j, la, lb;
    while (scanf("%d%d", &la, &lb) == 2 && la + lb != 0) {
        FOR(i,1,la) scanf("%d", a + i);
        FOR(i,1,lb) scanf("%d", b + i);
        FOR(i,1,la+lb) scanf("%d", c + i);

        FOR(i,0,la) FOR(j,0,lb)
            dp[i][j] =
                i == 0 && j == 0 ||
                i > 0 && a[i] == c[i + j] && dp[i - 1][j] ||
                j > 0 && b[j] == c[i + j] && dp[i][j - 1];
        
        puts(dp[la][lb] ? "possible" : "not possible");
    }

    return 0;
}